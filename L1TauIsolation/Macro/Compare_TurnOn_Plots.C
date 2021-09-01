{
  TString fileName_In = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/hist_turnOns_2021Calibration_2021IsoLUT_MC_VBF_20210727.root";
  TString fileName_Out = "/home/sbhowmik/RootTree/L1TauTrigger/Run3/L1TauIsolation_20210727/plots/plots_turnOns_2021Calibration_2021IsoLUT_MC_VBF_20210727";

  TFile fileIn(fileName_In.Data(),"READ");

  TString Threshold_NewLayer1_noIso = "46";
  TString Threshold_NewLayer1_Option1 = "45";
  TString Threshold_NewLayer1_Option2 = "45";
  TString Threshold_NewLayer1_Option3 = "45";
  TString Threshold_NewLayer1_Option4 = "46";
  TString Threshold_NewLayer1_Option5 = "46";
  TString Threshold_NewLayer1_Option6 = "46";
  TString Threshold_NewLayer1_Option7 = "46";
  TString Threshold_NewLayer1_Option8 = "35";
  TString Threshold_NewLayer1_Option9 = "46";
  TString Threshold_NewLayer1_Option10 = "46";
  TString Threshold_NewLayer1_Option11 = "46";
  TString Threshold_NewLayer1_Option12 = "46";
  TString Threshold_NewLayer1_Option13 = "46";
  TString Threshold_NewLayer1_Option14 = "46";
  TString Threshold_NewLayer1_Option15 = "46";
  TString Threshold_NewLayer1_Option16 = "46";
  TString Threshold_NewLayer1_Option17 = "46";
  TString Threshold_NewLayer1_Option18 = "46";
  TString Threshold_NewLayer1_Option19 = "46";
  TString Threshold_NewLayer1_Option20 = "46";
  TString Threshold_NewLayer1_Option21 = "46";
  TString Threshold_NewLayer1_Option22 = "35";
  TString Threshold_NewLayer1_Option31_extrap = "0";
  /*
  TString Threshold_NewLayer1_noIso = "38";
  TString Threshold_NewLayer1_Option1 = "26";
  TString Threshold_NewLayer1_Option2 = "30";
  TString Threshold_NewLayer1_Option3 = "32";
  TString Threshold_NewLayer1_Option4 = "33";
  TString Threshold_NewLayer1_Option5 = "34";
  TString Threshold_NewLayer1_Option6 = "36";
  TString Threshold_NewLayer1_Option7 = "36";
  TString Threshold_NewLayer1_Option8 = "29";
  TString Threshold_NewLayer1_Option9 = "36";
  TString Threshold_NewLayer1_Option10 = "37";
  TString Threshold_NewLayer1_Option11 = "37";
  TString Threshold_NewLayer1_Option12 = "38";
  TString Threshold_NewLayer1_Option13 = "38";
  TString Threshold_NewLayer1_Option14 = "38";
  TString Threshold_NewLayer1_Option15 = "34";
  TString Threshold_NewLayer1_Option16 = "38";
  TString Threshold_NewLayer1_Option17 = "38";
  TString Threshold_NewLayer1_Option18 = "38";
  TString Threshold_NewLayer1_Option19 = "38";
  TString Threshold_NewLayer1_Option20 = "38";
  TString Threshold_NewLayer1_Option21 = "35";
  TString Threshold_NewLayer1_Option22 = "30";
  TString Threshold_NewLayer1_Option31_extrap = "30";
  */
  /*
  TString Threshold_NewLayer1_noIso = "38";
  TString Threshold_NewLayer1_Option1 = "26";
  TString Threshold_NewLayer1_Option2 = "30";
  TString Threshold_NewLayer1_Option3 = "31";
  TString Threshold_NewLayer1_Option4 = "32";
  TString Threshold_NewLayer1_Option5 = "33";
  TString Threshold_NewLayer1_Option6 = "36";
  TString Threshold_NewLayer1_Option7 = "36";
  TString Threshold_NewLayer1_Option8 = "28";
  TString Threshold_NewLayer1_Option9 = "36";
  TString Threshold_NewLayer1_Option10 = "36";
  TString Threshold_NewLayer1_Option11 = "37";
  TString Threshold_NewLayer1_Option12 = "38";
  TString Threshold_NewLayer1_Option13 = "38";
  TString Threshold_NewLayer1_Option14 = "38";
  TString Threshold_NewLayer1_Option15 = "34";
  TString Threshold_NewLayer1_Option16 = "38";
  TString Threshold_NewLayer1_Option17 = "38";
  TString Threshold_NewLayer1_Option18 = "38";
  TString Threshold_NewLayer1_Option19 = "38";
  TString Threshold_NewLayer1_Option20 = "38";
  TString Threshold_NewLayer1_Option21 = "35";
  TString Threshold_NewLayer1_Option22 = "29";
  */

  TGraphAsymmErrors* eff_Stage2_iso_noIso = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_noIso_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option1 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option1_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option2 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option2_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option8 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option8_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option15 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option15_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option22 = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option22_by_pt");
  TGraphAsymmErrors* eff_Stage2_iso_Option31_extrap = (TGraphAsymmErrors*)fileIn.Get("divide_pt_pass_Option31_extrap_by_pt");

  eff_Stage2_iso_noIso->SetLineWidth(2);
  eff_Stage2_iso_Option1->SetLineWidth(2);
  eff_Stage2_iso_Option2->SetLineWidth(2);
  eff_Stage2_iso_Option8->SetLineWidth(2);
  eff_Stage2_iso_Option15->SetLineWidth(2);
  eff_Stage2_iso_Option22->SetLineWidth(2);
  eff_Stage2_iso_Option31_extrap->SetLineWidth(2);

  eff_Stage2_iso_noIso->SetLineColor(1);
  eff_Stage2_iso_Option1->SetLineColor(kMagenta);
  eff_Stage2_iso_Option2->SetLineColor(kBlue);
  eff_Stage2_iso_Option8->SetLineColor(kGreen);
  eff_Stage2_iso_Option15->SetLineColor(kCyan);
  eff_Stage2_iso_Option22->SetLineColor(kRed);
  eff_Stage2_iso_Option31_extrap->SetLineColor(kOrange);
  
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(eff_Stage2_iso_noIso,"l");
  //mg->Add(eff_Stage2_iso_Option1,"l");
  //mg->Add(eff_Stage2_iso_Option2,"l");
  //mg->Add(eff_Stage2_iso_Option8,"l");
  //mg->Add(eff_Stage2_iso_Option15,"l");
  mg->Add(eff_Stage2_iso_Option22,"l");
  mg->Add(eff_Stage2_iso_Option31_extrap,"l");

  TCanvas c("turnOns_new","turnOns_new",800,800);
  c.SetGrid();
  //c.SetLogx();
  
  mg->Draw("same");
  mg->GetXaxis()->SetLabelSize(0.025);
  mg->GetYaxis()->SetLabelSize(0.025);
  mg->GetXaxis()->SetTitle("p_{T}^{offl} [GeV]");
  mg->GetXaxis()->SetTitleOffset(1.1);
  mg->GetXaxis()->SetRangeUser(18.,100.);
  // mg->GetXaxis()->SetRangeUser(18.,1000.);
  // mg->GetXaxis()->SetRangeUser(0.,150.);
  mg->GetYaxis()->SetTitleOffset(1.43);
  mg->GetYaxis()->SetTitle("Single-#tau Efficiency");
  mg->SetTitle("");
  
  TLegend* leg = new TLegend(0.40,0.18,0.85,0.43);
  leg->SetBorderSize(0);
  leg->AddEntry(eff_Stage2_iso_noIso ,"#bf{2017 no-iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_noIso +" GeV)}","L");
  //leg->AddEntry(eff_Stage2_iso_Option1,"#bf{2017 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option1+" GeV) - Option 1}","L");
  //leg->AddEntry(eff_Stage2_iso_Option2,"#bf{2017 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option2+" GeV) - Option 2}","L");
  //leg->AddEntry(eff_Stage2_iso_Option8,"#bf{2017 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option8+" GeV) - Option 8}","L");
  //leg->AddEntry(eff_Stage2_iso_Option15,"#bf{2017 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option15+" GeV) - Option 15}","L");
  leg->AddEntry(eff_Stage2_iso_Option22,"#bf{2017 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option22+" GeV) - Option 22}","L");
  leg->AddEntry(eff_Stage2_iso_Option31_extrap,"#bf{2017 iso (E_{T}^{L1}#geq "+Threshold_NewLayer1_Option31_extrap+" GeV) - Option 31_extrap}","L");
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
