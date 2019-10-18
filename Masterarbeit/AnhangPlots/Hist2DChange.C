#include <TCanvas.h>
#include <TFile.h>

void Hist2DChange(){
	TFile *fout;
	TFile *f = TFile::Open("hists_mc_nE.root");

	TH2D *tt	= (TH2D*) f->Get("hclthetaclthetadouble");
	TH2D *pp	= (TH2D*) f->Get("hclphiclphidouble");
	
	gStyle->SetOptStat(0);
	fout=TFile::Open("ttpp.root","recreate");
	
	TCanvas *Cttpp = new TCanvas("Cttpp","",1240,480);
	Cttpp->Divide(2,1);
	Cttpp->cd(1);
	tt->Draw("colz");
	gPad->SetBottomMargin(0.12);
	gPad->SetLeftMargin(0.12);
	gPad->SetRightMargin(0.12);
	Cttpp->cd(2);
	pp->Draw("colz");
	gPad->SetBottomMargin(0.12);
	gPad->SetLeftMargin(0.12);
	gPad->SetRightMargin(0.12);
	tt->SetTitle("");
	pp->SetTitle("");
	double TitleS = 0.065;
	double TitleO = 0.85;
	double LabelS = 0.05;
	double LabelO = 0.006;


	tt->GetXaxis()->SetTitle("cluster(#theta) [radians]");
	tt->GetYaxis()->SetTitle("cluster(#theta) [radians]");

	pp->GetXaxis()->SetTitle("cluster(#phi) [radians]");
	pp->GetYaxis()->SetTitle("cluster(#phi) [radians]");

	tt->GetXaxis()->SetLabelSize(LabelS);
	tt->GetXaxis()->SetTitleSize(TitleS);
	tt->GetXaxis()->SetLabelOffset(LabelO);
	tt->GetXaxis()->SetTitleOffset(TitleO);
	tt->GetYaxis()->SetLabelSize(LabelS);
	tt->GetYaxis()->SetTitleSize(TitleS);
	tt->GetYaxis()->SetLabelOffset(LabelO);
	tt->GetYaxis()->SetTitleOffset(TitleO);
	tt->GetZaxis()->SetLabelSize(LabelS);
	tt->GetZaxis()->SetTitleSize(TitleS);
	tt->GetZaxis()->SetLabelOffset(LabelO);
	tt->GetZaxis()->SetTitleOffset(TitleO);

	pp->GetXaxis()->SetLabelSize(LabelS);
	pp->GetXaxis()->SetTitleSize(TitleS);
	pp->GetXaxis()->SetLabelOffset(LabelO);
	pp->GetXaxis()->SetTitleOffset(TitleO);
	pp->GetYaxis()->SetLabelSize(LabelS);
	pp->GetYaxis()->SetTitleSize(TitleS);
	pp->GetYaxis()->SetLabelOffset(LabelO);
	pp->GetYaxis()->SetTitleOffset(TitleO);
	pp->GetZaxis()->SetLabelSize(LabelS);
	pp->GetZaxis()->SetTitleSize(TitleS);
	pp->GetZaxis()->SetLabelOffset(LabelO);
	pp->GetZaxis()->SetTitleOffset(TitleO);




	Cttpp->SaveAs("ttpp.pdf");
	Cttpp->Write();
}
