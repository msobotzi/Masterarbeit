fillParticleList('gamma:all', 'clusterE > 0.01 and 0.296706 < theta < 2.61799', path=mypath)
fillParticleList('e+:all', 'clusterE > 0.01 and 0.296706 < theta < 2.61799', path=mypath)

reconstructDecay('vpho:gamma -> gamma:all', '', path=mypath)
reconstructDecay('vpho:elec -> e+:all', '', path=mypath)

copyLists(outputListName = 'vpho:ECLObjectUnranked', inputListNames=['vpho:elec', 'vpho:gamma'], path=mypath)

rankByHighest('vpho:ECLObjectUnranked', 'daughter(0,clusterE)', path=mypath)
cutAndCopyList('vpho:ECLObject', 'vpho:ECLObjectUnranked', '', path=mypath)
	
reconstructDecay('vpho:bhabha -> vpho:ECLObject vpho:ECLObject', '', path=mypath)

variablesToNtuple('vpho:bhabha', variables, treename = 'vpho_bhabha', filename = output.root, path=mypath)

