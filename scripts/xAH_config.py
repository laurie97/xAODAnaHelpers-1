import ROOT

def setMemberFunctions(obj, config):

    for user_opt in config: 
        if user_opt in dir(obj):
            print "Setting" , user_opt, "to", config[user_opt] 
            setattr(obj, user_opt, config[user_opt] )
        else: 
            print "ERROR: ", user_opt, "not a member of ", obj
            print dir(obj)
            import sys
            sys.exit(-1)

        

    return obj

def config_BasicEventSelection(Job, **kw):
    basicEventSel = ROOT.BasicEventSelection()
    setMemberFunctions(basicEventSel, kw)
    Job.algsAdd(basicEventSel)

def config_JetCalibrator(Job, **kw):
    jetCalib = ROOT.JetCalibrator()
    setMemberFunctions(jetCalib, kw)
    Job.algsAdd(jetCalib)

def config_JetSelector(Job, **kw):
    jetSelector = ROOT.JetSelector()
    setMemberFunctions(jetSelector, kw)
    Job.algsAdd(jetSelector)

def config_JetHistsAlgo(Job,  **kw):
    jetHists_alg = ROOT.JetHistsAlgo()
    setMemberFunctions(jetHists_alg, kw)
    Job.algsAdd(jetHists_alg)


#
# Following do not yet have all options implemented
#

def config_muonCalib(Job,name, **kw):
    muonCalib = ROOT.MuonCalibrator()
    muonCalib.m_name                 = name
    muonCalib.m_inContainerName      = kw.get('inContainerName'    , "")
    muonCalib.m_outContainerName     = kw.get('outContainerName'   , "")
    muonCalib.m_outputAlgoSystNames  = kw.get('outputAlgoSystNames', "")
    Job.algsAdd(muonCalib)



