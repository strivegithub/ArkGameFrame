// -------------------------------------------------------------------------
//    @FileName			:    NFIPluginManager.h
//    @Author           :    Ark Game Tech
//    @Date             :    2012-12-15
//    @Module           :    NFIPluginManager
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIModule.h"

#define FIND_MODULE(classBaseName, className)  \
	assert((TIsDerived<classBaseName, NFIModule>::Result));

class NFIPlugin;

class NFIPluginManager : public NFIModule
{
public:
    NFIPluginManager()
    {

    }

	template <typename T>
	T* FindModule()
	{
		NFIModule* pLogicModule = FindModule(typeid(T).name());
		if (pLogicModule)
		{
			if (!TIsDerived<T, NFIModule>::Result)
			{
				return NULL;
			}

			T* pT = dynamic_cast<T*>(pLogicModule);
			assert(NULL != pT);

			return pT;
		}
		assert(NULL);
		return NULL;
	}

    virtual void Registered(NFIPlugin* plugin) = 0;

    virtual void UnRegistered(NFIPlugin* plugin) = 0;

    virtual NFIPlugin* FindPlugin(const std::string& strPluginName) = 0;

    virtual void AddModule(const std::string& strModuleName, NFIModule* pModule) = 0;

    virtual void RemoveModule(const std::string& strModuleName) = 0;

    virtual NFIModule* FindModule(const std::string& strModuleName) = 0;

    virtual int AppID() const = 0;
    virtual NFINT64 GetInitTime() const = 0;
    virtual NFINT64 GetNowTime() const = 0;
	virtual const std::string& GetConfigPath() const = 0;
	virtual void SetConfigName(const std::string& strFileName) = 0;
};
