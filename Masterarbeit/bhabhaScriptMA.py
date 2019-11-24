#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import basf2
from basf2 import *
import modularAnalysis as ma
from modularAnalysis import *
from variables import variables as vm
from stdPhotons import stdPhotons
import os.path
import argparse
import softwaretrigger.variable_modules 


mypath=basf2.Path()

print(sys.argv)
try:
	out_name = int(sys.argv[1])
	out_name = sys.argv[1]
except:
	out_name = 100000;

value = int(out_name)

if(value <10000):
	ListName = '/group/belle2/dataprod/Data/release-03-02-02/DB00000654/proc9/e0003/4S/r02'+out_name+'*/all/mdst/sub00/*.root'

	use_central_database("data_reprocessing_proc9")
	print("Running on Data; Proc9")
	ma.inputMdstList('default',ListName ,path=mypath)
else:
	print("Running in MC")
	ma.inputMdstList('MC10','/home/belle2/msobotzi/gbasf2/sub00/mdst_000050_prod00004668_task10010000050.root' ,path=mypath)



fillParticleList('gamma:all','clusterE > 0.1 ',path=mypath)
fillParticleList('e+:all','clusterE > 0.1', path=mypath)

reconstructDecay('vpho:gamma -> gamma:all','', path=mypath)
reconstructDecay('vpho:elec -> e+:all','',path=mypath)

copyLists(outputListName='vpho:ECLObjectUnranked',inputListNames=['vpho:elec','vpho:gamma'],path=mypath)
rankByHighest('vpho:ECLObjectUnranked','daughter(0,clusterE)',path=mypath)
cutAndCopyList('vpho:ECLObject','vpho:ECLObjectUnranked','',path=mypath)

reconstructDecay('vpho:bhabha -> vpho:ECLObject vpho:ECLObject','',path=mypath)


if(value>10000):
	fillParticleListFromMC('e+:MC','clusterE>0.1', path=mypath)
	fillParticleListFromMC('gamma:MC','clusterE > 0.1',path=mypath)
	
	reconstructDecay('vpho:MCelec -> e+:MC','',path=mypath)
	reconstructDecay('vpho:MCgamma -> gamma:MC','', path=mypath)
	
	copyLists(outputListName='vpho:MCECLObjectUnranked',inputListNames=['vpho:MCelec','vpho:MCgamma'],path=mypath)
	rankByHighest('vpho:MCECLObjectUnranked','daughter(0,clusterE)',path=mypath)
	cutAndCopyList('vpho:MCECLObject','vpho:MCECLObjectUnranked','',path=mypath)
	
	reconstructDecay('vpho:MCbhabha -> vpho:MCECLObject vpho:MCECLObject','',path=mypath)
	matchMCTruth('vpho:MCbhabha',path=mypath)

var0 = ['M',
	'p',
        'E',
	'cosTheta',
	'theta',
	'phi',
	'clusterE',
	'pt',
        'clusterPhi',
        'clusterTheta',
	'b2bClusterPhi',
	'b2bClusterTheta',
	'b2bPhi',
	'b2bTheta',
        'nTracks',
	'charge',
	'PDG',
	'mcPDG',
	'isPrimarySignal',
	'isSignal',
	'nMCParticles',
	'mcE',
	'nMCMatches',
	'mcErrors',
	'mcTheta'
]

var1 = ['clusterTrigger',
	'nParticlesInList(gamma:all)',
	'nParticlesInList(vpho:ECLObject)',
	'nParticlesInList(vpho:bhabha)',
	'LBoost',
	'nTracks',
	'totalEnergyOfParticlesInList(vpho:ECLObject)',
	'totalEnergyOfParticlesInList(e+:all)',
	'totalEnergyOfParticlesInList(gamma:all)',
]
var_mc=[]
if (value>10000):
	var_mc=['totalEnergyOfParticlesInList(e+:MC)']
	

var_tag = []

for j in range(len(var0)):
    s_tag = 'eclObject_'+var0[j]
    vm.addAlias(s_tag, 'daughter(0,'+var0[j]+')')
    var_tag.append(s_tag)

var_vpho0=[]
var_vpho1=[]
for j in range(len(var0)):
	s_daughter_0 ='daughter_0_'+var0[j]
	s_daughter_1 ='daughter_1_'+var0[j]
	vm.addAlias(s_daughter_0, 'daughter(0,daughter(0,'+var0[j]+'))')
	vm.addAlias(s_daughter_1, 'daughter(1,daughter(0,'+var0[j]+'))')
	var_vpho0.append(s_daughter_0)
	var_vpho1.append(s_daughter_1)


var_trg = [
	'L1FTDLBit(10)',
	'L1FTDLBit(15)',
	'L1FTDLBit(35)',

]

var_vpho = var0 + var1 + var_mc + var_vpho0 + var_vpho1 + var_trg
var = var0 + var1 + var_tag + var_mc + var_trg

if(value<10000):
	outputName='bhabha_vpho_data_'+out_name+'.root'

else:
	outputName='bhabha_vpho_mc.root'
	variablesToNtuple('vpho:MCbhabha',var_vpho,treename='vpho_bhabha_FillFromMC',filename=outputName,path=mypath)

variablesToNtuple('vpho:bhabha',var_vpho,treename='vpho_bhabha',filename=outputName,path=mypath)
variablesToNtuple('vpho:ECLObject',var,treename='eclObject',filename=outputName,path=mypath)

basf2.process(mypath)

print(basf2.statistics)
