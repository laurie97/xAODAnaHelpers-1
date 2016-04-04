#ifndef xAODAnaHelpers_ClusterHists_H
#define xAODAnaHelpers_ClusterHists_H

#include "xAODAnaHelpers/HistogramManager.h"
#include "xAODCaloEvent/CaloClusterContainer.h"

class ClusterHists : public HistogramManager
{
  public:
    ClusterHists(std::string name, std::string detailStr );
    ~ClusterHists();

    StatusCode initialize();
    StatusCode execute( const xAOD::CaloClusterContainer* ccls, float eventWeight );
    StatusCode execute( const xAOD::CaloCluster* ccl, float eventWeight );
    using HistogramManager::book; // make other overloaded versions of book() to show up in subclass
    using HistogramManager::execute; // overload

  protected:
    // bools to control which histograms are filled
    bool m_fillDebugging;        //!

  private:
    // Histograms
    TH1F* m_ccl_n; //!
    TH1F* m_ccl_e; //!
    TH1F* m_ccl_pt; //!
    TH1F* m_ccl_eta; //!
    TH1F* m_ccl_phi; //!
    TH2F* m_ccl_eta_vs_phi; //!
    TH2F* m_ccl_e_vs_eta; //!
    TH2F* m_ccl_e_vs_phi; //!
    TH2F* m_ccl_pt_vs_eta; //!
    TH2F* m_ccl_pt_vs_phi; //!



    TH1F* m_ccl_e_0_0p8;
    TH1F* m_ccl_pt_0_0p8;
    TH1F* m_ccl_e_0_1p7;
    TH1F* m_ccl_pt_0_1p7;
    TH1F* m_ccl_e_1p7_5;
    TH1F* m_ccl_pt_1p7_5;
    TH1F* m_ccl_e_2p5_5;
    TH1F* m_ccl_pt_2p5_5;
    TH1F* m_ccl_e_3p5_5;
    TH1F* m_ccl_pt_3p5_5;
};


#endif
