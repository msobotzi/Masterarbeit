
#include <list>
#include <TFile.h>


void change(){

	TFile *fout;
	TFile *f;
	f = TFile::Open("hists_mc_nE.root");
	fout=TFile::Open("change.root","recreate");


	TH2D *p		= (TH2D*) f->Get("hclphiclphidouble");
	TH2D *t		= (TH2D*) f->Get("hclthetaclthetadouble");

 	double PPTXaxisSize = 0.075;
        double PPTXaxisOffset = 0.8;
        double PPTXLabelSize = 0.06;
        double PPTXLabelOffset = 0.006;
        double paxisSize=0.05;
        double PaxisOffset=0.8;
        double paxisOffset=0.005;
        double fPM_max=1;
        double IPM_max=1;
        double IPtM_max=1;
        double fPM_m=1;
        double norm =1;
        double PPTZLabelSize = 0.05;
        double iBMargin = 0.12;
        double fPtM_max;
        int p3DColor = 28;
        int p3MColor = 8;
	double XLabelSize = 0.05;
        double XLabelOffset = 0.0045;
        double XTitleSize = 0.07;
        double XTitleOffset = 0.75;
        TLine *ThetaECEff = new TLine(2.269,0,2.269,1);
        TLine *ThetaFCEff = new TLine(0.558,0,0.558,1);
        ThetaECEff->SetLineColor(6);
        ThetaFCEff->SetLineColor(6);
        TLine *ThetaECEff0 = new TLine(2.269,0,2.269,1);
        TLine *ThetaFCEff0 = new TLine(0.558,0,0.558,1);
        ThetaECEff0->SetLineColor(6);
        ThetaFCEff0->SetLineColor(6);
        vector<TCanvas*> xCanvas;
        TLatex latex;
        latex.SetTextSize(0.06);
        latex.SetTextAlign(13);
        TString title_p;
        TLatex xlatex;
        xlatex.SetTextSize(0.06);
        xlatex.SetTextAlign(13);
        double latexPhix = -2;
        double latexThetax = 0.85;
        double latexPhiy = .15;
        double latexThetay = .15;
	











	t->SetTitle("");
	t->GetXaxis()->SetTitleSize(XTitleSize);
	t->GetXaxis()->SetTitleOffset(XTitleOffset);

	t->GetXaxis()->SetLabelSize(XLabelSize);
	t->GetXaxis()->SetLabelOffset(XLabelOffset);

	t->GetYaxis()->SetTitleSize(XTitleSize);
	t->GetYaxis()->SetTitleOffset(XTitleOffset);

	t->GetYaxis()->SetLabelSize(XLabelSize);
	t->GetYaxis()->SetLabelOffset(XLabelOffset);


	t->GetZaxis()->SetTitleSize(XTitleSize);
	t->GetZaxis()->SetTitleOffset(XTitleOffset);

	t->GetZaxis()->SetLabelSize(XLabelSize);
	t->GetZaxis()->SetLabelOffset(XLabelOffset);



	p->SetTitle("");
	p->GetXaxis()->SetTitleSize(XTitleSize);
	p->GetXaxis()->SetTitleOffset(XTitleOffset);

	p->GetXaxis()->SetLabelSize(XLabelSize);
	p->GetXaxis()->SetLabelOffset(XLabelOffset);

	p->GetYaxis()->SetTitleSize(XTitleSize);
	p->GetYaxis()->SetTitleOffset(XTitleOffset);

	p->GetYaxis()->SetLabelSize(XLabelSize);
	p->GetYaxis()->SetLabelOffset(XLabelOffset);


	p->GetZaxis()->SetTitleSize(XTitleSize);
	p->GetZaxis()->SetTitleOffset(XTitleOffset);

	p->GetZaxis()->SetLabelSize(XLabelSize);
	p->GetZaxis()->SetLabelOffset(XLabelOffset);

	gStyle->SetOptStat(0);


	t->GetXaxis()->SetTitle("cluster(#theta_{1}) [radians]");
	t->GetYaxis()->SetTitle("cluster(#theta_{2}) [radians]");


	p->GetXaxis()->SetTitle("cluster(#phi_{1}) [radians]");
	p->GetYaxis()->SetTitle("cluster(#phi_{2}) [radians]");




	TCanvas *tp = new TCanvas("tp","",1080,480);
	tp->Divide(2,1);
	tp->cd(1);
	t->Draw("colz");
	gPad->SetBottomMargin(0.15);
	gPad->SetLeftMargin(0.15);
	gPad->SetRightMargin(0.15);
	tp->cd(2);
	p->Draw("colz");
	gPad->SetBottomMargin(0.15);
	gPad->SetLeftMargin(0.15);
	gPad->SetRightMargin(0.15);

	tp->SaveAs("ttpp.pdf");


}


