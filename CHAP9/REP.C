/*
 *         File:    rep.c
 *       Author:    SOMObjects Emitter Framework.
 *     Contents:    Generic framework implementation for ReportEmitter.
 *         Date:    Mon Jan  3 18:24:38 1994.
 */

#define ReportEmitter_Class_Source
#include <rep.ih>
#include <stdio.h>

SOM_Scope boolean  SOMLINK somtGenerateSections(ReportEmitter somSelf)
{
    ReportEmitterData *somThis = ReportEmitterGetData(somSelf);
    char buf[50];

    SOMTClassEntryC cls = __get_somtTargetClass(somSelf);
    SOMTTemplateOutputC template = __get_somtTemplate(somSelf);
    ReportEmitterMethodDebug("ReportEmitter","somtGenerateSections");

    /*
     * Setup symbols that are common to the whole file 
     */
    _somtFileSymbols(somSelf);

    if (cls != (SOMTClassEntryC) NULL) {
         _somtScanBases(somSelf,
                       "somtEmitBaseProlog",
                       "somtEmitBase",
                       "somtEmitBaseEpilog");
         _somtEmitClass(somSelf);    

        _somtScanAttributes(somSelf, "somtEmitAttributeProlog",
                            "somtEmitAttribute", "somtEmitAttributeEpilog");

        _somtScanMethods(somSelf,
                         "somtImplemented",
                         "somtEmitMethodsProlog",
                         "somtEmitMethod",
                         "somtEmitMethodsEpilog",
                         0);

        sprintf(buf, "%d", _numOfAttributes);
        _somtSetSymbolCopyBoth(template, "totalAttributes", buf);

        sprintf(buf, "%d", _numOfMethods);
        _somtSetSymbolCopyBoth(template, "totalMethods", buf);
        
        _somtOutputSection(template, "summaryS");
    }

    return (TRUE);
}

SOM_Scope void  SOMLINK somtEmitMethod(ReportEmitter somSelf, 
                                       SOMTMethodEntryC entry)
{
    ReportEmitterData *somThis = ReportEmitterGetData(somSelf);
    SOMTTemplateOutputC template = __get_somtTemplate(somSelf);

    ReportEmitterMethodDebug("ReportEmitter","somtEmitMethod");
   
    ReportEmitter_parent_SOMTEmitC_somtEmitMethod(somSelf, entry);

    _numOfMethods++;
}


SOM_Scope void  SOMLINK somtEmitAttribute(ReportEmitter somSelf, 
                                          SOMTAttributeEntryC att)
{
    ReportEmitterData *somThis = ReportEmitterGetData(somSelf);
    ReportEmitterMethodDebug("ReportEmitter","somtEmitAttribute");

    ReportEmitter_parent_SOMTEmitC_somtEmitAttribute(somSelf, 
                                                     att);
    _numOfAttributes++;
}

SOM_Scope void  SOMLINK somInit(ReportEmitter somSelf)
{
    ReportEmitterData *somThis = ReportEmitterGetData(somSelf);
    ReportEmitterMethodDebug("ReportEmitter","somInit");

    ReportEmitter_parent_SOMTEmitC_somInit(somSelf);

    _numOfAttributes = 0;
    _numOfMethods = 0;
}

