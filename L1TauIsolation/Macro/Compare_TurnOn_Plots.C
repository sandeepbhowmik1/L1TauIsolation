{
  TString fileName_In = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20211009/hist_turnOns_2021Calibration_2021IsoLUT_MC_VBF_20211009.root";
  TString fileName_Out = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20211009/plots/plots_turnOns_2021Calibration_2021IsoLUT_MC_VBF_20211009";

  TFile fileIn(fileName_In.Data(),"READ");

  TString Threshold_NewLayer1_noIso = "34";
  TString Threshold_NewLayer1_Option1 = "27";
  TString Threshold_NewLayer1_Option2 = "35";
  TString Threshold_NewLayer1_Option3 = "37";
  TString Threshold_NewLayer1_Option4 = "37";
  TString Threshold_NewLayer1_Option5 = "38";
  TString Threshold_NewLayer1_Option6 = "38";
  TString Threshold_NewLayer1_Option7 = "38";
  TString Threshold_NewLayer1_Option8 = "31";
  TString Threshold_NewLayer1_Option9 = "39";
  TString Threshold_NewLayer1_Option10 = "39";
  TString Threshold_NewLayer1_Option11 = "40";
  TString Threshold_NewLayer1_Option12 = "41";
  TString Threshold_NewLayer1_Option13 = "41";
  TString Threshold_NewLayer1_Option14 = "41";
  TString Threshold_NewLayer1_Option15 = "38";
  TString Threshold_NewLayer1_Option16 = "41";
  TString Threshold_NewLayer1_Option17 = "41";
  TString Threshold_NewLayer1_Option18 = "41";
  TString Threshold_NewLayer1_Option19 = "41";
  TString Threshold_NewLayer1_Option20 = "41";
  TString Threshold_NewLayer1_Option21 = "40";
  TString Threshold_NewLayer1_Option22 = "34";
  TString Threshold_NewLayer1_Option23 = "31";
  TString Threshold_NewLayer1_Option24 = "31";
  TString Threshold_NewLayer1_Option25 = "35";
  TString Threshold_NewLayer1_Option26 = "27";
  TString Threshold_NewLayer1_Option27 = "37";
  TString Threshold_NewLayer1_Option28 = "30";
  TString Threshold_NewLayer1_Option29 = "31";
  TString Threshold_NewLayer1_Option30 = "35";
  TString Threshold_NewLayer1_Option31 = "34";
  TString Threshold_NewLayer1_Option31_extrap = "34";

  TGraphAsymmErrors* eff_Stage2_iso_noIso = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option1 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option1_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option2 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option2_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option8 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option8_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option15 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option15_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option22_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option31 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option31_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option31_extrap = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option31_extrap_by_pt");

  eff_Stage2_iso_noIso->SetLineWidth(2);
  eff_Stage2_iso_Option1->SetLineWidth(2);
  eff_Stage2_iso_Option2->SetLineWidth(2);
  eff_Stage2_iso_Option8->SetLineWidth(2);
  eff_Stage2_iso_Option15->SetLineWidth(2);
  eff_Stage2_iso_Option22->SetLineWidth(2);
  eff_Stage2_iso_Option31->SetLineWidth(2);
  eff_Stage2_iso_Option31_extrap->SetLineWidth(2);

  eff_Stage2_iso_noIso->SetLineColor(1);
  eff_Stage2_iso_Option1->SetLineColor(2);
  eff_Stage2_iso_Option15->SetLineColor(3);
  eff_Stage2_iso_Option22->SetLineColor(4);
  eff_Stage2_iso_Option31->SetLineColor(6);
  eff_Stage2_iso_Option31_extrap->SetLineColor(2);
  
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(eff_Stage2_iso_noIso,"l");
  //mg->Add(eff_Stage2_iso_Option1,"l");
  //mg->Add(eff_Stage2_iso_Option2,"l");
  //mg->Add(eff_Stage2_iso_Option8,"l");
  //mg->Add(eff_Stage2_iso_Option15,"l");
  //mg->Add(eff_Stage2_iso_Option22,"l");
  //mg->Add(eff_Stage2_iso_Option31,"l");
  mg->Add(eff_Stage2_iso_Option31_extrap,"l");

  TCanvas c("turnOns_new","turnOns_new",800,800);
  c.SetGrid();
  //c.SetLogx();
  
  mg->Draw("same");
  mg->GetXaxis()->SetLabelSize(0.025);
  mg->GetYaxis()->SetLabelSize(0.025);
  mg->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  mg->GetXaxis()->SetTitleOffset(1.1);
  //mg->GetXaxis()->SetRangeUser(5.,100.);
  mg->GetXaxis()->SetRangeUser(0.,100.);
  // mg->GetXaxis()->SetRangeUser(0.,150.);
  mg->GetYaxis()->SetTitleOffset(1.43);
  mg->GetYaxis()->SetTitle("Single-#tau Efficiency");
  mg->SetTitle("");
  
  TLegend* leg = new TLegend(0.450,0.18,0.89,0.43);
  leg->SetBorderSize(0);
  leg->AddEntry(eff_Stage2_iso_noIso ,"#bf{2021 no-iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso +" GeV)}","L");
  //leg->AddEntry(eff_Stage2_iso_Option1,"#bf{2021 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option1+" GeV) - Option 1}","L");
  //leg->AddEntry(eff_Stage2_iso_Option2,"#bf{2021 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option2+" GeV) - Option 2}","L");
  //leg->AddEntry(eff_Stage2_iso_Option8,"#bf{2021 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option8+" GeV) - Option 8}","L");
  //leg->AddEntry(eff_Stage2_iso_Option15,"#bf{2021 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option15+" GeV) - Option 15}","L");
  //leg->AddEntry(eff_Stage2_iso_Option22,"#bf{2021 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22+" GeV) - Option 22}","L");
  //leg->AddEntry(eff_Stage2_iso_Option31,"#bf{2021 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option31+" GeV) - Option 31}","L");
  leg->AddEntry(eff_Stage2_iso_Option31_extrap,"#bf{2021 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option31_extrap+" GeV) - Option 31_extrap}","L");
  leg->Draw("same");

  TPaveText* texl = new TPaveText(0.20,0.89,0.70,0.96,"NDC");
  //texl->AddText("CMS Internal, #sqrt{s}=13 TeV, MC");
  //texl->AddText("CMS Internal, #sqrt{s}=13 TeV, 2018A Data");
  texl->AddText("#scale[1.5]{CMS} Internal         Run3 Simulation                14 TeV");

  texl->SetTextSize(0.03);
  texl->SetFillStyle(0);
  texl->SetBorderSize(0);
  texl->Draw("same");

  TString CanvasName = fileName_Out;
  TString PlotNamesOutPdf = CanvasName;
  PlotNamesOutPdf += ".pdf";
  TString PlotNamesOutPng = CanvasName;
  PlotNamesOutPng += ".png";
  TString PlotNamesOutRoot = CanvasName;
  PlotNamesOutRoot += ".root";

  c.SaveAs(PlotNamesOutPdf.Data());
  c.SaveAs(PlotNamesOutPng.Data());
  c.SaveAs(PlotNamesOutRoot.Data());
}
