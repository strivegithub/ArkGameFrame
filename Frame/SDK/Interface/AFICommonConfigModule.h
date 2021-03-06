/*****************************************************************************
// * This source file is part of ArkGameFrame                                *
// * For the latest info, see https://github.com/ArkGame                     *
// *                                                                         *
// * Copyright(c) 2013 - 2017 ArkGame authors.                               *
// *                                                                         *
// * Licensed under the Apache License, Version 2.0 (the "License");         *
// * you may not use this file except in compliance with the License.        *
// * You may obtain a copy of the License at                                 *
// *                                                                         *
// *     http://www.apache.org/licenses/LICENSE-2.0                          *
// *                                                                         *
// * Unless required by applicable law or agreed to in writing, software     *
// * distributed under the License is distributed on an "AS IS" BASIS,       *
// * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
// * See the License for the specific language governing permissions and     *
// * limitations under the License.                                          *
// *                                                                         *
// *                                                                         *
// * @file  	AFICommonConfigModule.h                                                *
// * @author    Ark Game Tech                                                *
// * @date      2015-12-15                                                   *
// * @brief     AFICommonConfigModule                                                  *
*****************************************************************************/
#ifndef AFI_COMMONCOAFIG_MODULE_H
#define AFI_COMMONCOAFIG_MODULE_H

#include <iostream>
#include "AFILogicModule.h"
#include "AFIBuffConfigModule.h"


class AFICommonConfigModule
    : public AFILogicModule
{
public:
    virtual bool ClearConfig() = 0;
    virtual const int GetAttributeInt(const std::string& strStructName, const std::string& strStructItemName, const std::string& strAttribute) = 0;
    virtual const int GetAttributeInt(const std::string& strStructName, const std::string& strSDKAttribute) = 0;
    virtual const std::string& GetAttributeString(const std::string& strStructName, const std::string& strStructItemName, const std::string& strAttribute) = 0;
    virtual const std::string& GetAttributeString(const std::string& strStructName, const std::string& strSDKAttribute) = 0;
    virtual bool LoadConfig(const std::string& strFile) = 0;
    virtual const int GetStructItemList(const std::string& strStructName, std::vector<std::string>& xList) = 0;
};

#endif

