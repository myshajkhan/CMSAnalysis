#include "Riostream.h" //automatically provides std;;
#include <iostream>
#include <fstream>
#include "TH1F.h"
#include "TCanvas.h"


void atlasdata(){
ifstream in; //ifstream is an input stream class in C++ that is used for reading data from files.
in.open(Form("ATLAS_higgs_test.dat")); //you are opening out.dat file 

//declaration of an object named ntuple -provides a way to store and organize data
TNtuple ntuple("ntuple", "data from ascii file", "Z1mass:Z2mass:mass4l:detajj:massjj:l1pdgid:l1pt:l1eta:l1phi:l2pdgid:l2pt:l2eta:l2phi:l3pdgid:l3pt:l3eta:l3phi:l4pdgid:l4pt:l4eta:l4phi:j1pt:j1eta:j1phi:j1E:j2pt:j2eta:j2phi:j2E:source");

Int_t nlines = 0; //variable is used to keep track of the number of lines read from the input file.
//declaring histograms for signal
auto f = TFile::Open("ATLAS_higgs_test.root","RECREATE");
TH1F sZ1mass("sZ1mass", "Z1mass distribution", 100, 0, 500);
TH1F sZ2mass("sZ2mass", "Z2mass distribution", 100, 0, 500);
TH1F smass4l("smass4l", "mass4l distribution", 100, 0, 300);
TH1F sdetajj("sdetajj", "detajj distribution", 100, 0, 10);
TH1F smassjj("smassjj", "massjj distribution", 100, 0, 500);
TH1I sl1pdgid("sl1pdgid", "l1pdgid distribution", 100, -50, 50);
TH1F sl1pt("sl1pt", "l1pt distribution", 100, 0, 500);
TH1F sl1eta("sl1eta", "l1eta distribution", 100, -5, 5);
TH1F sl1phi("sl1phi", "l1phi distribution", 100, -4, 4);
TH1I sl2pdgid("sl2pdgid", "l2pdgid distribution", 100, -15, 15);
TH1F sl2pt("sl2pt", "l2pt distribution", 100, 0, 300);
TH1F sl2eta("sl2eta", "l2eta distribution", 100, -5, 5);
TH1F sl2phi("sl2phi", "l2phi distribution", 100, -5, 5);
TH1I sl3pdgid("sl3pdgid", "l3pdgid distribution", 100, -15, 15);
TH1F sl3pt("sl3pt", "l3pt distribution", 100, 0, 300);
TH1F sl3eta("sl3eta", "l3eta distribution", 100, -5, 5);
TH1F sl3phi("sl3phi", "l3phi distribution", 100, -5, 5);
TH1I sl4pdgid("sl4pdgid", "l4pdgid distribution", 100, -15, 15);
TH1F sl4pt("sl4pt", "l4pt distribution", 100, 0, 100);
TH1F sl4eta("sl4eta", "l4eta distribution", 100, -5, 5);
TH1F sl4phi("sl4phi", "l4phi distribution", 100, -5, 5);
TH1F sj1pt("sj1pt", "j1pt distribution", 100, 0, 1000);
TH1F sj1eta("sj1eta", "j1eta distribution", 100, -5, 5);
TH1F sj1phi("sj1phi", "j1phi distribution", 100, -5, 5);
TH1F sj1E("sj1E", "j1E distribution", 100, 0, 3000);
TH1F sj2pt("sj2pt", "j2pt distribution", 100, 0, 500);
TH1F sj2eta("sj2eta", "j2eta distribution", 100, -5, 5);
TH1F sj2phi("sj2phi", "j2phi distribution", 100, -5, 5);
TH1F sj2E("sj2E", "j2E distribution", 100, 0, 2000);
//TH1I source("hsource", "source distribution", 10, 0, 10);
//declaring hists for background 

TH1F bZ1mass("bZ1mass", "Z1mass distribution", 100, 0, 500);
TH1F bZ2mass("bZ2mass", "Z2mass distribution", 100, 0, 500);
TH1F bmass4l("bmass4l", "mass4l distribution", 100, 0, 300);
TH1F bdetajj("bdetajj", "detajj distribution", 100, 0, 10);
TH1F bmassjj("bmassjj", "massjj distribution", 100, 0, 500);
TH1I bl1pdgid("bl1pdgid", "l1pdgid distribution", 100, -50, 50);
TH1F bl1pt("bl1pt", "l1pt distribution", 100, 0, 500);
TH1F bl1eta("bl1eta", "l1eta distribution", 100, -5, 5);
TH1F bl1phi("bl1phi", "l1phi distribution", 100, -5, 5);
TH1I bl2pdgid("bl2pdgid", "l2pdgid distribution", 100, -15, 15);
TH1F bl2pt("bl2pt", "l2pt distribution", 100, 0, 300);
TH1F bl2eta("bl2eta", "l2eta distribution", 100, -5, 5);
TH1F bl2phi("bl2phi", "l2phi distribution", 100, -5, 5);
TH1I bl3pdgid("bl3pdgid", "l3pdgid distribution", 100, -15, 15);
TH1F bl3pt("bl3pt", "l3pt distribution", 100, 0, 300);
TH1F bl3eta("bl3eta", "l3eta distribution", 100, -5, 5);
TH1F bl3phi("bl3phi", "l3phi distribution", 100, -5, 5);
TH1I bl4pdgid("bl4pdgid", "l4pdgid distribution", 100, -15, 15);
TH1F bl4pt("bl4pt", "l4pt distribution", 100, 0, 100);
TH1F bl4eta("bl4eta", "l4eta distribution", 100, -5, 5);
TH1F bl4phi("bl4phi", "l4phi distribution", 100, -5, 5);
TH1F bj1pt("bj1pt", "j1pt distribution", 100, 0, 1000);
TH1F bj1eta("bj1eta", "j1eta distribution", 100, -5, 5);
TH1F bj1phi("bj1phi", "j1phi distribution", 100, -5, 5);
TH1F bj1E("bj1E", "j1E distribution", 100, 0, 3000);
TH1F bj2pt("bj2pt", "j2pt distribution", 100, 0, 500);
TH1F bj2eta("bj2eta", "j2eta distribution", 100, -5, 5);
TH1F bj2phi("bj2phi", "j2phi distribution", 100, -5, 5);
TH1F bj2E("bj2E", "j2E distribution", 100, 0, 2000);


 // Create variables to hold the data
    double Z1mass, Z2mass, mass4l, detajj, massjj;
    int l1pdgid, l2pdgid, l3pdgid, l4pdgid;
    double l1pt, l1eta, l1phi, l2pt, l2eta, l2phi, l3pt, l3eta, l3phi, l4pt, l4eta, l4phi;
    double j1pt, j1eta, j1phi, j1E, j2pt, j2eta, j2phi, j2E;
    int  source ;


// create a TTree and it's braches so we can separate signal and background
   TTree *signal = new TTree("signal","signal or background");
  TTree *background = new TTree("background","signal or background");
while (1){
    in >> Z1mass >> Z2mass >> mass4l >> detajj >> massjj >> l1pdgid >> l1pt >> l1eta >> l1phi >> l2pdgid >> l2pt >> l2eta >> l2phi >> l3pdgid >> l3pt >> l3eta >> l3phi >> l4pdgid >> l4pt >> l4eta >> l4phi >> j1pt >> j1eta >> j1phi >> j1E >> j2pt >> j2eta >> j2phi >> j2E >> source;
    if (!in.good()) break;
  //  if (nlines < 10000) printf("Z1mass=%8f, Z2mass=%8f, mass4l=%8f, detajj=%8f, massjj=%8f, l1pdgid=%d, l1pt=%8f, l1eta=%8f, l1phi=%8f\n", Z1mass, Z2mass, mass4l, detajj, massjj, l1pdgid, l1pt, l1eta, l1phi);
        if (source== 1){   //when signal 
    signal->Branch("Z1mass", &Z1mass);
    signal->Branch("Z2mass", &Z2mass);
    signal->Branch("mass4l", &mass4l);
    signal->Branch("detajj", &detajj);
    signal->Branch("massjj", &massjj);
    signal->Branch("l1pdgid", &l1pdgid);
    signal->Branch("l1pt", &l1pt);
    signal->Branch("l1eta", &l1eta);
    signal->Branch("l1phi", &l1phi);
    signal->Branch("l2pdgid", &l2pdgid);
    signal->Branch("l2pt", &l2pt);
    signal->Branch("l2eta", &l2eta);
    signal->Branch("l2phi", &l2phi);
    signal->Branch("l3pdgid", &l3pdgid);
    signal->Branch("l3pt", &l3pt);
    signal->Branch("l3eta", &l3eta);
    signal->Branch("l3phi", &l3phi);
    signal->Branch("l4pdgid", &l4pdgid);
    signal->Branch("l4pt", &l4pt);
    signal->Branch("l4eta", &l4eta);
    signal->Branch("l4phi", &l4phi);
    signal->Branch("j1pt", &j1pt);
    signal->Branch("j1eta", &j1eta);
    signal->Branch("j1phi", &j1phi);
    signal->Branch("j1E", &j1E);
    signal->Branch("j2pt", &j2pt);
    signal->Branch("j2eta", &j2eta);
    signal->Branch("j2phi", &j2phi);
    signal->Branch("j2E", &j2E);



        
    sZ1mass.Fill(Z1mass);
    sZ2mass.Fill(Z2mass);
    smass4l.Fill(mass4l);
    sdetajj.Fill(detajj);
    smassjj.Fill(massjj);
    sl1pdgid.Fill(l1pdgid);
    sl1pt.Fill(l1pt);
    sl1eta.Fill(l1eta);
    sl1phi.Fill(l1phi);
    sl2pdgid.Fill(l2pdgid);
    sl2pt.Fill(l2pt);
    sl2eta.Fill(l2eta);
    sl2phi.Fill(l2phi);
    sl3pdgid.Fill(l3pdgid);
    sl3pt.Fill(l3pt);
    sl3eta.Fill(l3eta);
    sl3phi.Fill(l3phi);
    sl4pdgid.Fill(l4pdgid);
    sl4pt.Fill(l4pt);
    sl4eta.Fill(l4eta);
    sl4phi.Fill(l4phi);
    sj1pt.Fill(j1pt);
    sj1eta.Fill(j1eta);
    sj1phi.Fill(j1phi);
    sj1E.Fill(j1E);
    sj2pt.Fill(j2pt);
    sj2eta.Fill(j2eta);
    sj2phi.Fill(j2phi);
    sj2E.Fill(j2E);
  



} else {

    background->Branch("Z1mass", &Z1mass);
    background->Branch("Z2mass", &Z2mass);
    background->Branch("mass4l", &mass4l);
    background->Branch("detajj", &detajj);
    background->Branch("massjj", &massjj);
    background->Branch("l1pdgid", &l1pdgid);
    background->Branch("l1pt", &l1pt);
    background->Branch("l1eta", &l1eta);
    background->Branch("l1phi", &l1phi);
    background->Branch("l2pdgid", &l2pdgid);
    background->Branch("l2pt", &l2pt);
    background->Branch("l2eta", &l2eta);
    background->Branch("l2phi", &l2phi);
    background->Branch("l3pdgid", &l3pdgid);
    background->Branch("l3pt", &l3pt); 
    background->Branch("l3eta", &l3eta);
    background->Branch("l3phi", &l3phi);
    background->Branch("l4pdgid", &l4pdgid);
    background->Branch("l4pt", &l4pt);
    background->Branch("l4eta", &l4eta);
    background->Branch("l4phi", &l4phi);
    background->Branch("j1pt", &j1pt);
    background->Branch("j1eta", &j1eta);
    background->Branch("j1phi", &j1phi);
    background->Branch("j1E", &j1E);
    background->Branch("j2pt", &j2pt);
    background->Branch("j2eta", &j2eta);
    background->Branch("j2phi", &j2phi);
    background->Branch("j2E", &j2E);
  
  //filling the histogram for background

    bZ1mass.Fill(Z1mass);
    bZ2mass.Fill(Z2mass);
    bmass4l.Fill(mass4l);
    bdetajj.Fill(detajj);
    bmassjj.Fill(massjj);
    bl1pdgid.Fill(l1pdgid);
    bl1pt.Fill(l1pt);
    bl1eta.Fill(l1eta);
    bl1phi.Fill(l1phi);
    bl2pdgid.Fill(l2pdgid);
    bl2pt.Fill(l2pt);
    bl2eta.Fill(l2eta);
    bl2phi.Fill(l2phi);
    bl3pdgid.Fill(l3pdgid);
    bl3pt.Fill(l3pt);
    bl3eta.Fill(l3eta);
    bl3phi.Fill(l3phi);
    bl4pdgid.Fill(l4pdgid);
    bl4pt.Fill(l4pt);
    bl4eta.Fill(l4eta);
    bl4phi.Fill(l4phi);
    bj1pt.Fill(j1pt);
    bj1eta.Fill(j1eta);
    bj1phi.Fill(j1phi);
    bj1E.Fill(j1E);
    bj2pt.Fill(j2pt);
    bj2eta.Fill(j2eta);
    bj2phi.Fill(j2phi);
    bj2E.Fill(j2E);
  

}
    nlines++;
}

std::vector<TCanvas*> canvases;
//Drawing histograms
// Create the first canvas
TCanvas *c1 = new TCanvas("c1", "c1", 800, 800);
c1->Divide(2, 2);

c1->cd(1);
sZ1mass.SetLineColor(kBlue);
bZ1mass.SetLineColor(kRed);
sZ1mass.Draw();
bZ1mass.Draw("SAME");

c1->cd(2);
sZ2mass.SetLineColor(kBlue);
bZ2mass.SetLineColor(kRed);
sZ2mass.Draw();
bZ2mass.Draw("SAME");

c1->cd(3);
smass4l.SetLineColor(kBlue);
bmass4l.SetLineColor(kRed);
smass4l.Draw();
bmass4l.Draw("SAME");

c1->cd(4);
sdetajj.SetLineColor(kBlue);
bdetajj.SetLineColor(kRed);
sdetajj.Draw();
bdetajj.Draw("SAME");

c1->Update();
 
// Create the second canvas
TCanvas *c2 = new TCanvas("c2", "c2", 800, 800);
c2->Divide(2, 2);

c2->cd(1);
smassjj.SetLineColor(kBlue);
bmassjj.SetLineColor(kRed);
smassjj.Draw();
bmassjj.Draw("SAME");

c2->cd(2);
sl1pdgid.SetLineColor(kBlue);
bl1pdgid.SetLineColor(kRed);
sl1pdgid.Draw();
bl1pdgid.Draw("SAME");

c2->cd(3);
sl1pt.SetLineColor(kBlue);
bl1pt.SetLineColor(kRed);
sl1pt.Draw();
bl1pt.Draw("SAME");

c2->cd(4);
sl1eta.SetLineColor(kBlue);
bl1eta.SetLineColor(kRed);
sl1eta.Draw();
bl1eta.Draw("SAME");

c2->Update();

// Create the third canvas
TCanvas *c3 = new TCanvas("c3", "c3", 800, 800);
c3->Divide(2, 2);

c3->cd(1);
sl1phi.SetLineColor(kBlue);
bl1phi.SetLineColor(kRed);
sl1phi.Draw();
bl1phi.Draw("SAME");

c3->cd(2);
sl2pdgid.SetLineColor(kBlue);
bl2pdgid.SetLineColor(kRed);
sl2pdgid.Draw();
bl2pdgid.Draw("SAME");

c3->cd(3);
sl2pt.SetLineColor(kBlue);
bl2pt.SetLineColor(kRed);
sl2pt.Draw();
bl2pt.Draw("SAME");

c3->cd(4);
sl2eta.SetLineColor(kBlue);
bl2eta.SetLineColor(kRed);
sl2eta.Draw();
bl2eta.Draw("SAME");

c3->Update();

// Create the fourth canvas
TCanvas *c4 = new TCanvas("c4", "c4", 800, 800);
c4->Divide(2, 2);

c4->cd(1);
sl2phi.SetLineColor(kBlue);
bl2phi.SetLineColor(kRed);
sl2phi.Draw();
bl2phi.Draw("SAME");

c4->cd(2);
sl3pdgid.SetLineColor(kBlue);
bl3pdgid.SetLineColor(kRed);
sl3pdgid.Draw();
bl3pdgid.Draw("SAME");

c4->Update();
 
// Create canvas 5
TCanvas *c5 = new TCanvas("c5", "c5", 800, 800);
c5->Divide(2, 2);

c5->cd(1);
sl3phi.SetLineColor(kBlue);
bl3phi.SetLineColor(kRed);
sl3phi.Draw();
bl3phi.Draw("SAME");

c5->cd(2);


c5->cd(3);
sj1pt.SetLineColor(kBlue);
bj1pt.SetLineColor(kRed);
sj1pt.Draw();
bj1pt.Draw("SAME");

c5->cd(4);
sj1eta.SetLineColor(kBlue);
bj1eta.SetLineColor(kRed);
sj1eta.Draw();
bj1eta.Draw("SAME");

c5->Update();

// Create canvas 6
TCanvas *c6 = new TCanvas("c6", "c6", 800, 800);
c6->Divide(2, 2);

c6->cd(1);
sj1phi.SetLineColor(kBlue);
bj1phi.SetLineColor(kRed);
sj1phi.Draw();
bj1phi.Draw("SAME");

c6->cd(2);
sj2pt.SetLineColor(kBlue);
bj2pt.SetLineColor(kRed);
sj2pt.Draw();
bj2pt.Draw("SAME");


c6->cd(3);

sj2eta.SetLineColor(kBlue);
bj2eta.SetLineColor(kRed);
sj2eta.Draw();
bj2eta.Draw("SAME");

c6->cd(4);

sj2phi.SetLineColor(kBlue);
bj2phi.SetLineColor(kRed);
sj2phi.Draw();
bj2phi.Draw("SAME");

c6->Update();

c1->SaveAs("histograms1.pdf"); 
c2->SaveAs("histograms2.pdf"); 
c3->SaveAs("histograms3.pdf"); 
c4->SaveAs("histograms4.pdf"); 
c5->SaveAs("histograms5.pdf"); 
c6->SaveAs("histograms6.pdf"); 
  








std::cout << " found " << nlines << " points" << std::endl;
in.close();

f->Write();

}
