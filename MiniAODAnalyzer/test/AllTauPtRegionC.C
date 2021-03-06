#include <iostream>
#include "TLatex.h"
#include <iomanip>
#include <vector>
#include "TPad.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TSystem.h"
#include "TImage.h"
#include "TKey.h"
#include "TH1.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TObjArray.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TPostScript.h"
#include <TPaveStats.h>
#include "TLegend.h"
#include <TProfile.h>
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "THStack.h"

int AllTauPtRegionC() {

  double lumi=4.353; //--inv fb--//

  unsigned long long evt_DYJetsToLL_M50=1;
  unsigned long long evt_TT=1;
  unsigned long long evt_WJetsToLNu=1;
  //  TH1::SetDefaultSumw2(); 
  //  gROOT->SetBatch(kTRUE);
  //  TFile *file_DYJetsToLL_M50  = new TFile("../python/crab_projects/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/results/hist.root");
  //double xs_DYJetsToLL_M50=6104000; //--fb--//

  TFile *file_DYJetsToLL_M50  = new TFile("../python/crab_projects/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");             
  double xs_DYJetsToLL_M50=4895000;  //--fb--//                                                                                                                    

  //  TFile *file_DYJetsToLL_M5to50  = new TFile("../python/crab_projects/crab_DYJetsToLL_M-5to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");    
  //  double xs_DYJetsToLL_M5to50=;  //--fb--//                                                                                                                    

  TFile *file_TT              = new TFile("../python/crab_projects/crab_TT_TuneCUETP8M1_13TeV-powheg-pythia8/results/hist.root");
  double xs_TT=730000; //--fb--//

  //TFile *file_WJetsToLNu      = new TFile("../python/crab_projects/crab_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/results/hist.root");
  //double xs_WJetsToLNu=60290000; //--fb--//

  ////  TFile *file_WJetsToLNu      = new TFile("../python/crab_projects/crab_WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  ////  double xs_WJetsToLNu= 50690000; //--fb--//

  TFile *file_WJetsToLNu_HT100To200  = new TFile("../python/crab_projects/crab_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_WJetsToLNu_HT100To200 = 1345000 ; //--fb--//

  TFile *file_WJetsToLNu_HT200To400  = new TFile("../python/crab_projects/crab_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_WJetsToLNu_HT200To400 = 359700 ; //--fb--//

  TFile *file_WJetsToLNu_HT400To600  = new TFile("../python/crab_projects/crab_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_WJetsToLNu_HT400To600 = 48910 ; //--fb--//

  TFile *file_WJetsToLNu_HT600To800  = new TFile("../python/crab_projects/crab_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_WJetsToLNu_HT600To800 = 12050 ; //--fb--//

  TFile *file_WJetsToLNu_HT800To1200  = new TFile("../python/crab_projects/crab_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_WJetsToLNu_HT800To1200 = 5501 ; //--fb--//

  TFile *file_WJetsToLNu_HT1200To2500  = new TFile("../python/crab_projects/crab_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_WJetsToLNu_HT1200To2500 = 1329 ; //--fb--//

  TFile *file_WJetsToLNu_HT2500ToInf  = new TFile("../python/crab_projects/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_WJetsToLNu_HT2500ToInf = 32.16  ; //--fb--//

  TFile *file_ST_tchannel_antitop=new TFile("../python/crab_projects/crab_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/results/hist.root");
  double xs_ST_tchannel_antitop = 80950; //--fb--//
  //
  TFile *file_ST_tchannel_top=new TFile("../python/crab_projects/crab_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/results/hist.root");
  double xs_ST_tchannel_top = 103200; //--fb--//
  //
  TFile *file_ST_tW_antitop=new TFile("../python/crab_projects/crab_ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/results/hist.root");
  double xs_ST_tW_antitop = 38090; //--fb--//
  //
  TFile *file_ST_tW_top=new TFile("../python/crab_projects/crab_ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/results/hist.root");
  double xs_ST_tW_top = 38090; //--fb--//
  //
  TFile *file_WW=new TFile("../python/crab_projects/crab_WW_TuneCUETP8M1_13TeV-pythia8/results/hist.root");
  double xs_WW = 63210; //--fb--//
  //
  TFile *file_WZ=new TFile("../python/crab_projects/crab_WZ_TuneCUETP8M1_13TeV-pythia8/results/hist.root");
  double xs_WZ = 22820; //--fb--//
  //
  TFile *file_ZZ=new TFile("../python/crab_projects/crab_ZZ_TuneCUETP8M1_13TeV-pythia8/results/hist.root");
  double xs_ZZ = 10320; //--fb--//
  //
  TFile *file_QCD_HT200to300=new TFile("../python/crab_projects/crab_QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_QCD_HT200to300 = 1717000000; //--fb--//
  //
  TFile *file_QCD_HT300to500=new TFile("../python/crab_projects/crab_QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_QCD_HT300to500 = 351300000; //--fb--//
  //
  TFile *file_QCD_HT500to700=new TFile("../python/crab_projects/crab_QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_QCD_HT500to700 = 31630000 ; //--fb--//
  //
  TFile *file_QCD_HT700to1000=new TFile("../python/crab_projects/crab_QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_QCD_HT700to1000 = 6802000 ; //--fb--//
  //
  TFile *file_QCD_HT1000to1500=new TFile("../python/crab_projects/crab_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_QCD_HT1000to1500 = 1206000 ; //--fb--//
  //
  TFile *file_QCD_HT1500to2000=new TFile("../python/crab_projects/crab_QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_QCD_HT1500to2000 = 120400 ; //--fb--//
  //
  TFile *file_QCD_HT2000toInf=new TFile("../python/crab_projects/crab_QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/results/hist.root");
  double xs_QCD_HT2000toInf = 25250 ; //--fb--//
  //
  TFile *file_ZJetsToNuNu_HT100To200 =new TFile("../python/crab_projects/crab_ZJetsToNuNu_HT-100To200_13TeV-madgraph/results/hist.root");
  double xs_ZJetsToNuNu_HT100To200 =  280350; //--fb--//
  //
  TFile *file_ZJetsToNuNu_HT200To400 =new TFile("../python/crab_projects/crab_ZJetsToNuNu_HT-200To400_13TeV-madgraph/results/hist.root");
  double xs_ZJetsToNuNu_HT200To400 = 77670 ; //--fb--//
  //
  TFile *file_ZJetsToNuNu_HT400To600 =new TFile("../python/crab_projects/crab_ZJetsToNuNu_HT-400To600_13TeV-madgraph/results/hist.root");
  double xs_ZJetsToNuNu_HT400To600 = 10730 ; //--fb--//
  //
  TFile *file_ZJetsToNuNu_HT600To800 =new TFile("../python/crab_projects/crab_ZJetsToNuNu_HT-600To800_13TeV-madgraph/results/hist.root");
  double xs_ZJetsToNuNu_HT600To800 = 853 ; //--fb--//
  //
  TFile *file_ZJetsToNuNu_HT800To1200 =new TFile("../python/crab_projects/crab_ZJetsToNuNu_HT-800To1200_13TeV-madgraph/results/hist.root");
  double xs_ZJetsToNuNu_HT800To1200 = 394.2 ; //--fb--//
  //
  TFile *file_ZJetsToNuNu_HT1200To2500 =new TFile("../python/crab_projects/crab_ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/results/hist.root");
  double xs_ZJetsToNuNu_HT1200To2500 = 97.4 ; //--fb--//
  //
  TFile *file_ZJetsToNuNu_HT2500ToInf =new TFile("../python/crab_projects/crab_ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/results/hist.root");
  double xs_ZJetsToNuNu_HT2500ToInf = 2.308 ; //--fb--//

  /// DATA ///
  TFile *file_Tau_Run2016D = new TFile("../python/crab_projects/crab_Tau_Run2016D_PromptReco_v2/results/hist.root");

  /// Signal ///
  TFile *file_Wprime_M1000 = new TFile("../python/crab_projects/crab_WprimeToTauNu_M-1000_TuneCUETP8M1_13TeV-pythia8-tauola/results/hist.root");
  double xs_Wprime_M1000= 3060; // --fb-- //

  //--//
  TH1D* h1_evt_DYJetsToLL_M50 = (TH1D*)file_DYJetsToLL_M50->Get("demo/eventCount");
  evt_DYJetsToLL_M50 = h1_evt_DYJetsToLL_M50->GetEntries(); // Integral();
  // std::cout << "Total evt_DYJetsToLL_M50 = " << evt_DYJetsToLL_M50 << std::endl;
  double wt_DYJetsToLL_M50 = (xs_DYJetsToLL_M50*lumi)/evt_DYJetsToLL_M50 ;
  TH1D* tauPt_RegC_Stage1_DYJetsToLL_M50 = (TH1D*)file_DYJetsToLL_M50->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //  tauPt_RegC_Stage1_DYJetsToLL_M50->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_DYJetsToLL_M50->SetBinErrorOption(TH1::kPoisson);
  //  std::cout << "Selected **DY** unweighted nevt=" << tauPt_RegC_Stage1_DYJetsToLL_M50->Integral() << std::endl;
  //  std::cout << "wt_DYJetsToLL_M50 = " << wt_DYJetsToLL_M50 << std::endl;
  tauPt_RegC_Stage1_DYJetsToLL_M50->Scale(wt_DYJetsToLL_M50);
  tauPt_RegC_Stage1_DYJetsToLL_M50->SetFillColorAlpha(kRed,0.5);
  tauPt_RegC_Stage1_DYJetsToLL_M50->SetLineColor(kBlack);
  tauPt_RegC_Stage1_DYJetsToLL_M50->Rebin(2);  
  std::cout << "Selected **DY** weighted nevt=" << tauPt_RegC_Stage1_DYJetsToLL_M50->Integral() << std::endl;

  TH1D* h1_evt_TT = (TH1D*)file_TT->Get("demo/eventCount");
  evt_TT = h1_evt_TT->GetEntries(); // Integral();
  std::cout << "evt_TT = " << evt_TT << std::endl;
  double wt_TT = (xs_TT*lumi)/evt_TT ;
  TH1D* tauPt_RegC_Stage1_TT  = (TH1D*)file_TT->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //  tauPt_RegC_Stage1_TT->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_TT->SetBinErrorOption(TH1::kPoisson);
  std::cout << "**TTbar** unweighted nevt=" << tauPt_RegC_Stage1_TT->Integral() << std::endl;
  std::cout << "wt_TT = " << wt_TT << std::endl;
  tauPt_RegC_Stage1_TT->Scale(wt_TT);
  tauPt_RegC_Stage1_TT->SetFillColor(kBlue-7);
  tauPt_RegC_Stage1_TT->SetLineColor(kBlack);
  tauPt_RegC_Stage1_TT->Rebin(2);
  std::cout << "**TTbar** weighted nevt=" << tauPt_RegC_Stage1_TT->Integral() << std::endl;

  /*
  TH1D* h1_evt_WJetsToLNu = (TH1D*)file_WJetsToLNu->Get("demo/eventCount");
  evt_WJetsToLNu = h1_evt_WJetsToLNu->GetEntries(); //Integral();
  std::cout << "evt_WJetsToLNu = " << evt_WJetsToLNu << std::endl;
  double wt_WJetsToLNu = (xs_WJetsToLNu*lumi)/evt_WJetsToLNu ;
  TH1D* tauPt_RegC_Stage1_WJetsToLNu  = (TH1D*)file_WJetsToLNu->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  tauPt_RegC_Stage1_WJetsToLNu->Sumw2(kFALSE);
  tauPt_RegC_Stage1_WJetsToLNu->SetBinErrorOption(TH1::kPoisson);
  std::cout << "**WJets** unweighted nevt=" << tauPt_RegC_Stage1_WJetsToLNu->Integral() << std::endl;
  std::cout << "wt_WJetsToLNu = " << wt_WJetsToLNu << std::endl;
  tauPt_RegC_Stage1_WJetsToLNu->Scale(wt_WJetsToLNu);
  tauPt_RegC_Stage1_WJetsToLNu->SetFillColorAlpha(kGreen-7,0.5);
  tauPt_RegC_Stage1_WJetsToLNu->SetLineColor(kGreen-7);
  tauPt_RegC_Stage1_WJetsToLNu->Rebin(20);
  std::cout << "**WJets** weighted nevt=" << tauPt_RegC_Stage1_WJetsToLNu->Integral() << std::endl;
  */

  //file_ST_tchannel_antitop
  TH1D* h1_evt_ST_tchannel_antitop = (TH1D*)file_ST_tchannel_antitop->Get("demo/eventCount");
  unsigned long long evt_ST_tchannel_antitop = h1_evt_ST_tchannel_antitop->GetEntries(); //Integral();
  double wt_ST_tchannel_antitop = (xs_ST_tchannel_antitop*lumi)/evt_ST_tchannel_antitop ;
  TH1D* tauPt_RegC_Stage1_ST_tchannel_antitop  = (TH1D*)file_ST_tchannel_antitop->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //  tauPt_RegC_Stage1_ST_tchannel_antitop->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_ST_tchannel_antitop->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ST_tchannel_antitop->Scale(wt_ST_tchannel_antitop);
 
  //file_ST_tchannel_top
  TH1D* h1_evt_ST_tchannel_top = (TH1D*)file_ST_tchannel_top->Get("demo/eventCount");
  unsigned long long evt_ST_tchannel_top = h1_evt_ST_tchannel_top->GetEntries(); //Integral();
  double wt_ST_tchannel_top = (xs_ST_tchannel_top*lumi)/evt_ST_tchannel_top ;
  TH1D* tauPt_RegC_Stage1_ST_tchannel_top  = (TH1D*)file_ST_tchannel_top->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //  tauPt_RegC_Stage1_ST_tchannel_top->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_ST_tchannel_top->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ST_tchannel_top->Scale(wt_ST_tchannel_top);

  //file_ST_tW_antitop
  TH1D* h1_evt_ST_tW_antitop = (TH1D*)file_ST_tW_antitop->Get("demo/eventCount");
  unsigned long long evt_ST_tW_antitop = h1_evt_ST_tW_antitop->GetEntries(); //Integral();
  double wt_ST_tW_antitop = (xs_ST_tW_antitop*lumi)/evt_ST_tW_antitop ;
  TH1D* tauPt_RegC_Stage1_ST_tW_antitop  = (TH1D*)file_ST_tW_antitop->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //  tauPt_RegC_Stage1_ST_tW_antitop->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_ST_tW_antitop->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ST_tW_antitop->Scale(wt_ST_tW_antitop);
  
  //file_ST_tW_top
  TH1D* h1_evt_ST_tW_top = (TH1D*)file_ST_tW_top->Get("demo/eventCount");
  unsigned long long evt_ST_tW_top = h1_evt_ST_tW_top->GetEntries(); //Integral();
  double wt_ST_tW_top = (xs_ST_tW_top*lumi)/evt_ST_tW_top ;
  TH1D* tauPt_RegC_Stage1_ST_tW_top  = (TH1D*)file_ST_tW_top->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //  tauPt_RegC_Stage1_ST_tW_top->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_ST_tW_top->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ST_tW_top->Scale(wt_ST_tW_top);

  TH1D* total_ST = (TH1D*)tauPt_RegC_Stage1_ST_tchannel_antitop->Clone(); 
  total_ST->Add(tauPt_RegC_Stage1_ST_tchannel_top);
  total_ST->Add(tauPt_RegC_Stage1_ST_tW_antitop);
  total_ST->Add(tauPt_RegC_Stage1_ST_tW_top);
  total_ST->SetFillColorAlpha(kCyan,0.5);
  total_ST->SetLineColor(kBlack);
  total_ST->Rebin(2);

  //file_WJetsToLNu_HT100To200
  TH1D* h1_evt_WJetsToLNu_HT100To200 = (TH1D*)file_WJetsToLNu_HT100To200->Get("demo/eventCount");
  unsigned long long evt_WJetsToLNu_HT100To200 = h1_evt_WJetsToLNu_HT100To200->GetEntries(); //Integral();                                                                 
  double wt_WJetsToLNu_HT100To200 = (xs_WJetsToLNu_HT100To200*lumi)/evt_WJetsToLNu_HT100To200 ;
  TH1D* tauPt_RegC_Stage1_WJetsToLNu_HT100To200  = (TH1D*)file_WJetsToLNu_HT100To200->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //                           
  //  tauPt_RegC_Stage1_WJetsToLNu_HT100To200->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_WJetsToLNu_HT100To200->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WJetsToLNu_HT100To200->Scale(wt_WJetsToLNu_HT100To200);

  //file_WJetsToLNu_HT200To400
  TH1D* h1_evt_WJetsToLNu_HT200To400 = (TH1D*)file_WJetsToLNu_HT200To400->Get("demo/eventCount");
  unsigned long long evt_WJetsToLNu_HT200To400 = h1_evt_WJetsToLNu_HT200To400->GetEntries(); //Integral();                                                                 
  double wt_WJetsToLNu_HT200To400 = (xs_WJetsToLNu_HT200To400*lumi)/evt_WJetsToLNu_HT200To400 ;
  TH1D* tauPt_RegC_Stage1_WJetsToLNu_HT200To400  = (TH1D*)file_WJetsToLNu_HT200To400->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //                                                                                                                                                      
  // tauPt_RegC_Stage1_WJetsToLNu_HT200To400->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_WJetsToLNu_HT200To400->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WJetsToLNu_HT200To400->Scale(wt_WJetsToLNu_HT200To400);

  //file_WJetsToLNu_HT400To600
  TH1D* h1_evt_WJetsToLNu_HT400To600 = (TH1D*)file_WJetsToLNu_HT400To600->Get("demo/eventCount");
  unsigned long long evt_WJetsToLNu_HT400To600 = h1_evt_WJetsToLNu_HT400To600->GetEntries(); //Integral();                                                                 
  double wt_WJetsToLNu_HT400To600 = (xs_WJetsToLNu_HT400To600*lumi)/evt_WJetsToLNu_HT400To600 ;
  TH1D* tauPt_RegC_Stage1_WJetsToLNu_HT400To600  = (TH1D*)file_WJetsToLNu_HT400To600->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //                                                                                                                                                      
  // tauPt_RegC_Stage1_WJetsToLNu_HT400To600->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_WJetsToLNu_HT400To600->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WJetsToLNu_HT400To600->Scale(wt_WJetsToLNu_HT400To600);

  //file_WJetsToLNu_HT600To800
  TH1D* h1_evt_WJetsToLNu_HT600To800 = (TH1D*)file_WJetsToLNu_HT600To800->Get("demo/eventCount");
  unsigned long long evt_WJetsToLNu_HT600To800 = h1_evt_WJetsToLNu_HT600To800->GetEntries(); //Integral();                                                                 
  double wt_WJetsToLNu_HT600To800 = (xs_WJetsToLNu_HT600To800*lumi)/evt_WJetsToLNu_HT600To800 ;
  TH1D* tauPt_RegC_Stage1_WJetsToLNu_HT600To800  = (TH1D*)file_WJetsToLNu_HT600To800->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //                                                                                                                                                      
  //  tauPt_RegC_Stage1_WJetsToLNu_HT600To800->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_WJetsToLNu_HT600To800->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WJetsToLNu_HT600To800->Scale(wt_WJetsToLNu_HT600To800);

  //file_WJetsToLNu_HT800To1200
  TH1D* h1_evt_WJetsToLNu_HT800To1200 = (TH1D*)file_WJetsToLNu_HT800To1200->Get("demo/eventCount");
  unsigned long long evt_WJetsToLNu_HT800To1200 = h1_evt_WJetsToLNu_HT800To1200->GetEntries(); //Integral();                                                                 
  double wt_WJetsToLNu_HT800To1200 = (xs_WJetsToLNu_HT800To1200*lumi)/evt_WJetsToLNu_HT800To1200 ;
  TH1D* tauPt_RegC_Stage1_WJetsToLNu_HT800To1200  = (TH1D*)file_WJetsToLNu_HT800To1200->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //                                                                                                                                                      
  // tauPt_RegC_Stage1_WJetsToLNu_HT800To1200->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_WJetsToLNu_HT800To1200->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WJetsToLNu_HT800To1200->Scale(wt_WJetsToLNu_HT800To1200);

  //file_WJetsToLNu_HT1200To2500
  TH1D* h1_evt_WJetsToLNu_HT1200To2500 = (TH1D*)file_WJetsToLNu_HT1200To2500->Get("demo/eventCount");
  unsigned long long evt_WJetsToLNu_HT1200To2500 = h1_evt_WJetsToLNu_HT1200To2500->GetEntries(); //Integral();                                                             
  double wt_WJetsToLNu_HT1200To2500 = (xs_WJetsToLNu_HT1200To2500*lumi)/evt_WJetsToLNu_HT1200To2500 ;
  TH1D* tauPt_RegC_Stage1_WJetsToLNu_HT1200To2500  = (TH1D*)file_WJetsToLNu_HT1200To2500->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //                                                                                                                                                      
  // tauPt_RegC_Stage1_WJetsToLNu_HT1200To2500->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_WJetsToLNu_HT1200To2500->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WJetsToLNu_HT1200To2500->Scale(wt_WJetsToLNu_HT1200To2500);

  //file_WJetsToLNu_HT2500ToInf
  TH1D* h1_evt_WJetsToLNu_HT2500ToInf = (TH1D*)file_WJetsToLNu_HT2500ToInf->Get("demo/eventCount");
  unsigned long long evt_WJetsToLNu_HT2500ToInf = h1_evt_WJetsToLNu_HT2500ToInf->GetEntries(); //Integral();                                                             
  double wt_WJetsToLNu_HT2500ToInf = (xs_WJetsToLNu_HT2500ToInf*lumi)/evt_WJetsToLNu_HT2500ToInf ;
  TH1D* tauPt_RegC_Stage1_WJetsToLNu_HT2500ToInf  = (TH1D*)file_WJetsToLNu_HT2500ToInf->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //                                                                                                                                                      
  //tauPt_RegC_Stage1_WJetsToLNu_HT2500ToInf->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_WJetsToLNu_HT2500ToInf->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WJetsToLNu_HT2500ToInf->Scale(wt_WJetsToLNu_HT2500ToInf);


  TH1D* total_WJets = (TH1D*)tauPt_RegC_Stage1_WJetsToLNu_HT100To200->Clone();
  total_WJets->Add(tauPt_RegC_Stage1_WJetsToLNu_HT200To400);
  total_WJets->Add(tauPt_RegC_Stage1_WJetsToLNu_HT400To600);
  total_WJets->Add(tauPt_RegC_Stage1_WJetsToLNu_HT600To800);
  total_WJets->Add(tauPt_RegC_Stage1_WJetsToLNu_HT800To1200);
  total_WJets->Add(tauPt_RegC_Stage1_WJetsToLNu_HT1200To2500);
  total_WJets->Add(tauPt_RegC_Stage1_WJetsToLNu_HT2500ToInf);
  total_WJets->SetFillColorAlpha(kGreen-8,0.5);
  total_WJets->SetLineColor(kBlack);
  total_WJets->Rebin(2);


  //file_WW
  TH1D* h1_evt_WW = (TH1D*)file_WW->Get("demo/eventCount");
  unsigned long long evt_WW = h1_evt_WW->GetEntries(); //Integral();                                                                         
  double wt_WW = (xs_WW*lumi)/evt_WW ;
  TH1D* tauPt_RegC_Stage1_WW  = (TH1D*)file_WW->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_WW->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_WW->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WW->Scale(wt_WW);

  //file_WZ
  TH1D* h1_evt_WZ = (TH1D*)file_WZ->Get("demo/eventCount");
  unsigned long long evt_WZ = h1_evt_WZ->GetEntries(); //Integral();                                                                         
  double wt_WZ = (xs_WZ*lumi)/evt_WZ ;
  TH1D* tauPt_RegC_Stage1_WZ  = (TH1D*)file_WZ->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_WZ->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_WZ->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_WZ->Scale(wt_WZ);

  //file_ZZ
  TH1D* h1_evt_ZZ = (TH1D*)file_ZZ->Get("demo/eventCount");
  unsigned long long evt_ZZ = h1_evt_ZZ->GetEntries(); //Integral();                                                                         
  double wt_ZZ = (xs_ZZ*lumi)/evt_ZZ ;
  TH1D* tauPt_RegC_Stage1_ZZ  = (TH1D*)file_ZZ->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_ZZ->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_ZZ->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ZZ->Scale(wt_ZZ);
 
  TH1D* total_diboson = (TH1D*)tauPt_RegC_Stage1_WW->Clone();
  total_diboson->Add(tauPt_RegC_Stage1_WZ);
  total_diboson->Add(tauPt_RegC_Stage1_ZZ);
  total_diboson->SetFillColorAlpha(kOrange+2,0.5);
  total_diboson->SetLineColor(kBlack);
  total_diboson->Rebin(2);

  //file_QCD_HT200to300
  TH1D* h1_evt_QCD_HT200to300 = (TH1D*)file_QCD_HT200to300->Get("demo/eventCount");
  unsigned long long evt_QCD_HT200to300 = h1_evt_QCD_HT200to300->GetEntries(); //Integral();                                                                 
  double wt_QCD_HT200to300 = (xs_QCD_HT200to300*lumi)/evt_QCD_HT200to300 ;
  TH1D* tauPt_RegC_Stage1_QCD_HT200to300  = (TH1D*)file_QCD_HT200to300->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_QCD_HT200to300->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_QCD_HT200to300->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_QCD_HT200to300->Scale(wt_QCD_HT200to300);

  //file_QCD_HT300to500
  TH1D* h1_evt_QCD_HT300to500 = (TH1D*)file_QCD_HT300to500->Get("demo/eventCount");
  unsigned long long evt_QCD_HT300to500 = h1_evt_QCD_HT300to500->GetEntries(); //Integral();                                                                     
  double wt_QCD_HT300to500 = (xs_QCD_HT300to500*lumi)/evt_QCD_HT300to500 ;
  TH1D* tauPt_RegC_Stage1_QCD_HT300to500  = (TH1D*)file_QCD_HT300to500->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  // tauPt_RegC_Stage1_QCD_HT300to500->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_QCD_HT300to500->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_QCD_HT300to500->Scale(wt_QCD_HT300to500);

  //file_QCD_HT500to700
  TH1D* h1_evt_QCD_HT500to700 = (TH1D*)file_QCD_HT500to700->Get("demo/eventCount");
  unsigned long long evt_QCD_HT500to700 = h1_evt_QCD_HT500to700->GetEntries(); //Integral();                                                                
  double wt_QCD_HT500to700 = (xs_QCD_HT500to700*lumi)/evt_QCD_HT500to700 ;
  TH1D* tauPt_RegC_Stage1_QCD_HT500to700  = (TH1D*)file_QCD_HT500to700->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_QCD_HT500to700->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_QCD_HT500to700->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_QCD_HT500to700->Scale(wt_QCD_HT500to700);

  //file_QCD_HT700to1000
  TH1D* h1_evt_QCD_HT700to1000 = (TH1D*)file_QCD_HT700to1000->Get("demo/eventCount");
  unsigned long long evt_QCD_HT700to1000 = h1_evt_QCD_HT700to1000->GetEntries(); //Integral();                                                                
  double wt_QCD_HT700to1000 = (xs_QCD_HT700to1000*lumi)/evt_QCD_HT700to1000 ;
  TH1D* tauPt_RegC_Stage1_QCD_HT700to1000  = (TH1D*)file_QCD_HT700to1000->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_QCD_HT700to1000->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_QCD_HT700to1000->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_QCD_HT700to1000->Scale(wt_QCD_HT700to1000);

  //file_QCD_HT1000to1500
  TH1D* h1_evt_QCD_HT1000to1500 = (TH1D*)file_QCD_HT1000to1500->Get("demo/eventCount");
  unsigned long long evt_QCD_HT1000to1500 = h1_evt_QCD_HT1000to1500->GetEntries(); //Integral();                                                                  
  double wt_QCD_HT1000to1500 = (xs_QCD_HT1000to1500*lumi)/evt_QCD_HT1000to1500 ;
  TH1D* tauPt_RegC_Stage1_QCD_HT1000to1500  = (TH1D*)file_QCD_HT1000to1500->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  // tauPt_RegC_Stage1_QCD_HT1000to1500->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_QCD_HT1000to1500->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_QCD_HT1000to1500->Scale(wt_QCD_HT1000to1500);

  //file_QCD_HT1500to2000
  TH1D* h1_evt_QCD_HT1500to2000 = (TH1D*)file_QCD_HT1500to2000->Get("demo/eventCount");
  unsigned long long evt_QCD_HT1500to2000 = h1_evt_QCD_HT1500to2000->GetEntries(); //Integral();                                                                  
  double wt_QCD_HT1500to2000 = (xs_QCD_HT1500to2000*lumi)/evt_QCD_HT1500to2000 ;
  TH1D* tauPt_RegC_Stage1_QCD_HT1500to2000  = (TH1D*)file_QCD_HT1500to2000->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_QCD_HT1500to2000->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_QCD_HT1500to2000->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_QCD_HT1500to2000->Scale(wt_QCD_HT1500to2000);

  //file_QCD_HT2000toInf
  TH1D* h1_evt_QCD_HT2000toInf = (TH1D*)file_QCD_HT2000toInf->Get("demo/eventCount");
  unsigned long long evt_QCD_HT2000toInf = h1_evt_QCD_HT2000toInf->GetEntries(); //Integral();                                                                  
  double wt_QCD_HT2000toInf = (xs_QCD_HT2000toInf*lumi)/evt_QCD_HT2000toInf ;
  TH1D* tauPt_RegC_Stage1_QCD_HT2000toInf  = (TH1D*)file_QCD_HT2000toInf->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_QCD_HT2000toInf->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_QCD_HT2000toInf->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_QCD_HT2000toInf->Scale(wt_QCD_HT2000toInf);

  TH1D* total_QCD = (TH1D*)tauPt_RegC_Stage1_QCD_HT200to300->Clone();
  total_QCD->Add(tauPt_RegC_Stage1_QCD_HT300to500);
  total_QCD->Add(tauPt_RegC_Stage1_QCD_HT500to700);
  total_QCD->Add(tauPt_RegC_Stage1_QCD_HT700to1000);
  total_QCD->Add(tauPt_RegC_Stage1_QCD_HT1000to1500);
  total_QCD->Add(tauPt_RegC_Stage1_QCD_HT1500to2000);
  total_QCD->Add(tauPt_RegC_Stage1_QCD_HT2000toInf);
  total_QCD->SetFillColorAlpha(kPink+1,0.5);
  total_QCD->SetLineColor(kBlack);
  total_QCD->Rebin(2);

  //file_ZJetsToNuNu_HT100To200
  TH1D* h1_evt_ZJetsToNuNu_HT100To200 = (TH1D*)file_ZJetsToNuNu_HT100To200->Get("demo/eventCount");
  unsigned long long evt_ZJetsToNuNu_HT100To200 = h1_evt_ZJetsToNuNu_HT100To200->GetEntries(); //Integral();                                                                  
  double wt_ZJetsToNuNu_HT100To200 = (xs_ZJetsToNuNu_HT100To200*lumi)/evt_ZJetsToNuNu_HT100To200 ;
  TH1D* tauPt_RegC_Stage1_ZJetsToNuNu_HT100To200  = (TH1D*)file_ZJetsToNuNu_HT100To200->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT100To200->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT100To200->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ZJetsToNuNu_HT100To200->Scale(wt_ZJetsToNuNu_HT100To200);

  //file_ZJetsToNuNu_HT200To400
  TH1D* h1_evt_ZJetsToNuNu_HT200To400 = (TH1D*)file_ZJetsToNuNu_HT200To400->Get("demo/eventCount");
  unsigned long long evt_ZJetsToNuNu_HT200To400 = h1_evt_ZJetsToNuNu_HT200To400->GetEntries(); //Integral();                                                                  
  double wt_ZJetsToNuNu_HT200To400 = (xs_ZJetsToNuNu_HT200To400*lumi)/evt_ZJetsToNuNu_HT200To400 ;
  TH1D* tauPt_RegC_Stage1_ZJetsToNuNu_HT200To400  = (TH1D*)file_ZJetsToNuNu_HT200To400->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_ZJetsToNuNu_HT200To400->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_ZJetsToNuNu_HT200To400->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ZJetsToNuNu_HT200To400->Scale(wt_ZJetsToNuNu_HT200To400);

  //file_ZJetsToNuNu_HT400To600
  TH1D* h1_evt_ZJetsToNuNu_HT400To600 = (TH1D*)file_ZJetsToNuNu_HT400To600->Get("demo/eventCount");
  unsigned long long evt_ZJetsToNuNu_HT400To600 = h1_evt_ZJetsToNuNu_HT400To600->GetEntries(); //Integral();                                                                  
  double wt_ZJetsToNuNu_HT400To600 = (xs_ZJetsToNuNu_HT400To600*lumi)/evt_ZJetsToNuNu_HT400To600 ;
  TH1D* tauPt_RegC_Stage1_ZJetsToNuNu_HT400To600  = (TH1D*)file_ZJetsToNuNu_HT400To600->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT400To600->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT400To600->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ZJetsToNuNu_HT400To600->Scale(wt_ZJetsToNuNu_HT400To600);

  //file_ZJetsToNuNu_HT600To800
  TH1D* h1_evt_ZJetsToNuNu_HT600To800 = (TH1D*)file_ZJetsToNuNu_HT600To800->Get("demo/eventCount");
  unsigned long long evt_ZJetsToNuNu_HT600To800 = h1_evt_ZJetsToNuNu_HT600To800->GetEntries(); //Integral();                                                                  
  double wt_ZJetsToNuNu_HT600To800 = (xs_ZJetsToNuNu_HT600To800*lumi)/evt_ZJetsToNuNu_HT600To800 ;
  TH1D* tauPt_RegC_Stage1_ZJetsToNuNu_HT600To800  = (TH1D*)file_ZJetsToNuNu_HT600To800->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_ZJetsToNuNu_HT600To800->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT600To800->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ZJetsToNuNu_HT600To800->Scale(wt_ZJetsToNuNu_HT600To800);

  //file_ZJetsToNuNu_HT800To1200
  TH1D* h1_evt_ZJetsToNuNu_HT800To1200 = (TH1D*)file_ZJetsToNuNu_HT800To1200->Get("demo/eventCount");
  unsigned long long evt_ZJetsToNuNu_HT800To1200 = h1_evt_ZJetsToNuNu_HT800To1200->GetEntries(); //Integral();                                                            
  double wt_ZJetsToNuNu_HT800To1200 = (xs_ZJetsToNuNu_HT800To1200*lumi)/evt_ZJetsToNuNu_HT800To1200 ;
  TH1D* tauPt_RegC_Stage1_ZJetsToNuNu_HT800To1200  = (TH1D*)file_ZJetsToNuNu_HT800To1200->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT800To1200->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_ZJetsToNuNu_HT800To1200->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ZJetsToNuNu_HT800To1200->Scale(wt_ZJetsToNuNu_HT800To1200);

  //file_ZJetsToNuNu_HT1200To2500
  TH1D* h1_evt_ZJetsToNuNu_HT1200To2500 = (TH1D*)file_ZJetsToNuNu_HT1200To2500->Get("demo/eventCount");
  unsigned long long evt_ZJetsToNuNu_HT1200To2500 = h1_evt_ZJetsToNuNu_HT1200To2500->GetEntries(); //Integral();                                                             
  double wt_ZJetsToNuNu_HT1200To2500 = (xs_ZJetsToNuNu_HT1200To2500*lumi)/evt_ZJetsToNuNu_HT1200To2500 ;
  TH1D* tauPt_RegC_Stage1_ZJetsToNuNu_HT1200To2500  = (TH1D*)file_ZJetsToNuNu_HT1200To2500->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT1200To2500->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT1200To2500->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ZJetsToNuNu_HT1200To2500->Scale(wt_ZJetsToNuNu_HT1200To2500);

  //file_ZJetsToNuNu_HT2500ToInf
  TH1D* h1_evt_ZJetsToNuNu_HT2500ToInf = (TH1D*)file_ZJetsToNuNu_HT2500ToInf->Get("demo/eventCount");
  unsigned long long evt_ZJetsToNuNu_HT2500ToInf = h1_evt_ZJetsToNuNu_HT2500ToInf->GetEntries(); //Integral();                                                         
  double wt_ZJetsToNuNu_HT2500ToInf = (xs_ZJetsToNuNu_HT2500ToInf*lumi)/evt_ZJetsToNuNu_HT2500ToInf ;
  TH1D* tauPt_RegC_Stage1_ZJetsToNuNu_HT2500ToInf  = (TH1D*)file_ZJetsToNuNu_HT2500ToInf->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT2500ToInf->Sumw2(kFALSE);
  // tauPt_RegC_Stage1_ZJetsToNuNu_HT2500ToInf->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_ZJetsToNuNu_HT2500ToInf->Scale(wt_ZJetsToNuNu_HT2500ToInf);

  TH1D* total_ZJets = (TH1D*)tauPt_RegC_Stage1_ZJetsToNuNu_HT100To200->Clone();
  total_ZJets->Add(tauPt_RegC_Stage1_ZJetsToNuNu_HT200To400);
  total_ZJets->Add(tauPt_RegC_Stage1_ZJetsToNuNu_HT400To600);
  total_ZJets->Add(tauPt_RegC_Stage1_ZJetsToNuNu_HT600To800);
  total_ZJets->Add(tauPt_RegC_Stage1_ZJetsToNuNu_HT800To1200);
  total_ZJets->Add(tauPt_RegC_Stage1_ZJetsToNuNu_HT1200To2500);
  total_ZJets->Add(tauPt_RegC_Stage1_ZJetsToNuNu_HT2500ToInf);
  total_ZJets->SetFillColorAlpha(kYellow-9,0.5);
  total_ZJets->SetLineColor(kBlack);
  total_ZJets->Rebin(2);

  //--Data--//
  TH1D* tauPt_RegC_Stage1_Run2016D  = (TH1D*)file_Tau_Run2016D->Get("demo/tauPt_RegC_Stage1");
  // Poisson error //
  //tauPt_RegC_Stage1_Run2016D->Sumw2(kFALSE);
  //tauPt_RegC_Stage1_Run2016D->SetBinErrorOption(TH1::kPoisson);
  tauPt_RegC_Stage1_Run2016D->SetMarkerStyle(20);
  tauPt_RegC_Stage1_Run2016D->SetMarkerColor(kBlack);
  tauPt_RegC_Stage1_Run2016D->SetLineColor(kBlack);
  tauPt_RegC_Stage1_Run2016D->Rebin(2);

  //--Signal--//
  TH1D* h1_evt_Wprime_M1000 = (TH1D*)file_Wprime_M1000->Get("demo/eventCount");
  unsigned long long evt_Wprime_M1000 = h1_evt_Wprime_M1000->GetEntries(); //Integral();                                                                          
  std::cout << "evt_Wprime_M1000 = " << evt_Wprime_M1000 << std::endl;
  double wt_Wprime_M1000 = (xs_Wprime_M1000*lumi)/evt_Wprime_M1000 ;
  TH1D* tauPt_RegC_Stage1_Wprime_M1000  = (TH1D*)file_Wprime_M1000->Get("demo/tauPt_RegC_Stage1");
  tauPt_RegC_Stage1_Wprime_M1000->Scale(wt_Wprime_M1000);
  //  tauPt_RegC_Stage1_Wprime_M1000->SetFillColorAlpha(kGreen-7,0.5);
  tauPt_RegC_Stage1_Wprime_M1000->SetLineColor(kMagenta);
  tauPt_RegC_Stage1_Wprime_M1000->SetLineWidth(2);
  tauPt_RegC_Stage1_Wprime_M1000->SetLineStyle(5);
  tauPt_RegC_Stage1_Wprime_M1000->Rebin(2);
 
  //--Plotting Styles//
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadBottomMargin(0.12);  
  gStyle->SetPadTopMargin(0.05);   
  gStyle->SetTitleXSize(0.05);
  gStyle->SetTitleXOffset(1.05);
  gStyle->SetTitleYSize(0.05);
  gStyle->SetTitleYOffset(1.05);

  //////// Output File /////////
  TFile* outputFile = new TFile("Out_tauPt_RegC_Stage1.root","RECREATE");
  outputFile->cd();

  //--//
  THStack *hs = new THStack("hs","");
  // hs->Add(tauPt_RegC_Stage1_WJetsToLNu);
  hs->Add(total_WJets);
  hs->Add(tauPt_RegC_Stage1_TT);
  hs->Add(tauPt_RegC_Stage1_DYJetsToLL_M50);
  hs->Add(total_ST);
  hs->Add(total_diboson);
  hs->Add(total_QCD);
  hs->Add(total_ZJets);
  //tauPt_RegC_Stage1_->SetTitle("");
    /*
  eff1->GetYaxis()->SetTitle("Events");
  //eff1->SetMarkerStyle(0);
  //eff1->SetMarkerColor(kBlack);
  eff1->SetLineColor(kBlack);
  eff1->SetLineWidth(2);
  */
  TCanvas* my_canvas = new TCanvas("canvas","canvas",800,600);
  my_canvas->cd();
  //  hs->Draw();
  gPad->SetLogy();
  hs->Draw("HIST");                                                                                                                                        
  hs->SetMaximum(100000);
  hs->SetMinimum(0.0001);
  hs->GetXaxis()->SetLimits(50, 1200);
  hs->GetXaxis()->SetTitle("p_{T}");
  hs->GetYaxis()->SetTitle("Events");
  
  //TH1F* total =  (TH1F*)hs->GetStack()->Last()->Clone();
  //total->SetFillStyle(3004);                                                                                                                                      
  //total->SetFillColor(kGray+1); 
  //  total->SetMarkerColor(0);
  // total->Draw("SAME E2");
  //hs->GetStack()->Last()->Draw("same E");
  // hs->Draw("SAME HIST");
  //my_canvas->Update();
  //my_canvas->Update();
  tauPt_RegC_Stage1_Wprime_M1000->Draw("SAME HIST");
  tauPt_RegC_Stage1_Run2016D->Draw("SAME E0");

  //  hs->SetOption("HIST L");
  TLatex* Region_text = new TLatex(0.50,0.70,"Region C");
  Region_text->SetNDC();
  Region_text->SetTextSize(0.04);
  Region_text->SetTextAngle(0);
  Region_text->Draw("same");
  
  TLatex* CMS_text = new TLatex(0.20,0.90,"CMS");
  CMS_text->SetNDC();
  CMS_text->SetTextSize(0.05);
  CMS_text->SetTextAngle(0);
  CMS_text->Draw("same");
  TLatex* CMS_text_2 = new TLatex(0.20,0.85,"Preliminary");
  CMS_text_2->SetNDC();
  CMS_text_2->SetTextFont(42);
  CMS_text_2->SetTextSize(0.05);
  CMS_text_2->SetTextAngle(0);
  CMS_text_2->Draw("same");    

  TLatex* lumiText = new TLatex(0.95,0.975,"4.35 fb^{-1} (13 TeV)");
  lumiText->SetNDC();
  lumiText->SetTextFont(42);
  lumiText->SetTextSize(0.04);
  lumiText->SetTextAlign(32);
  lumiText->Draw("same");     

  TLegend *leg_example = new TLegend(0.75,0.60,0.94,0.94);
  leg_example->SetFillColor(0);
  leg_example->SetTextFont(42);
  leg_example->SetBorderSize(0);
  leg_example->AddEntry(total_WJets, "Wjets","f");
  leg_example->AddEntry(tauPt_RegC_Stage1_DYJetsToLL_M50, "DY","f");
  leg_example->AddEntry(tauPt_RegC_Stage1_TT, "t#bar{t}","f");
  //leg_example->AddEntry(tauPt_RegC_Stage1_WJetsToLNu, "Wjets","f");
  leg_example->AddEntry(total_ST, "Single Top", "f");
  leg_example->AddEntry(total_diboson, "Diboson", "f");
  leg_example->AddEntry(total_QCD, "QCD", "f");
  leg_example->AddEntry(total_ZJets, "Z#rightarrow#nu#nu", "f");
  leg_example->AddEntry(tauPt_RegC_Stage1_Wprime_M1000, "SSM W' 1 TeV", "l");
  leg_example->AddEntry(tauPt_RegC_Stage1_Run2016D, "Data", "pl" );
  leg_example->Draw("same");
  
  my_canvas->Write();
  my_canvas->Print("tauPt_RegC_Stage1.pdf");
  /*
  TCanvas* my_canvas2 = new TCanvas("canvas2","canvas2");
  my_canvas2->cd();
  gPad->SetLogy();
  total->SetMaximum(1000);
  total->SetMarkerStyle(20);
  total->Draw("E");
  my_canvas2->Write();
  */
  return 0;

}
