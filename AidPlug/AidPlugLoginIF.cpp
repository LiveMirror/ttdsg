/**
  @(#)$Id$
  * @(#)
  *
  * (c)  XIAOTING PRIVATE PERSON  2014
  * All Rights Reserved.
  */

/**
  @brief   Plug-in (Plug-in, also known as addin, add-in, addon or add-on, also translated plug) is a follow certain standardized 
  application program interface to write out the procedure.

  @Author $Author$
  @Date $Date$
  @Revision $Revision$
  @URL $URL$
  @Header $Header$
 */
#include "stdafx.h"

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

#ifndef AIDPLUGEYLOGIN_H
#include "AidPlugEYLogin.h"
#endif

#ifndef AIDPLUGPLOGIN_H
#include "AidPlugPLogin.h"
#endif

AidPlugLoginIF* AidPlugLoginIF::s_pcInstance =  NULL;
const CString AidPlugLoginIF::CSTRING_ANTICRACK[24] = {
	_T("D527FF2946CE4E0F0C9D668822E5EE54"),
	_T("D99894F55B4A16EA480335B21741759A"),
	_T("D08B4D151E248321C8B5EAC29C311C07"),
	_T("D19E4751FCA997009CA5E25A0441CCA7"),
	_T("DBDD2921C0B015BC696580ED032559E5"),
	_T("D86B85B7A6D708AEB63443E86A291B04"),
	_T("DE6E22DE4D727586DD41509FBDBD04FC"),
	_T("DA991C4237D16C1808AB993868BF0404"),
	_T("D2C8693BA7396A05C5428925FEC770CC"),
	_T("D29BAE0BEC8C11E4A318642582155428"),
	_T("DAC238A76E752D1ACA3EE6ED8FBC5F5B"),
	_T("D7BF46AD1F3B3A3ECC5A6CC221462B29"),
	_T("DD2ABFEEB27605200590E201E3A681A5"),
	_T("D08FE78EE19C47A166A06AEFC6A96DAE"),
	_T("D65789BA24BCC14339DDC6242F2A05A0"),
	_T("D2424F86790D614E61AF68F89C56FD80"),
	_T("DB9722EB8D210DE8C5BD021F1FC3039D"),
	_T("D053F42FC801F45758998039AE1090A3"),
	_T("DB2F4DF4EA2CCD6931C49705402D94D3"),
	_T("D94583907F093629E659276F267BD93C"),
	_T("D9937B9B753BB4B3A9E4E1236B80B7EF"),
	_T("D0A3C30563EE9ADA21890BCA83574CD1"),
	_T("DB4B69E4CC4726319FE88D7DAE7570D1"),
	_T("WCF0C86D3FCCAC53DEAF15A5F19B3BB3")
};

AidPlugLoginIF* 
AidPlugLoginIF::Instance(void)
{
	if (NULL == s_pcInstance) {
		s_pcInstance = new AidPlugLoginIF;
	}
	return s_pcInstance;
}

void
AidPlugLoginIF::Destroy(void)
{
	if (NULL != s_pcInstance) {
		delete s_pcInstance;
		s_pcInstance = NULL;
	}
}

AidPlugLoginIF::AidPlugLoginIF():
m_pPlugLogin(NULL)
{
	if (NULL == m_pPlugLogin){
//		m_pPlugLogin = new AidPlugEYLogin;
		m_pPlugLogin = new AidPlugPLogin;
	}
}

AidPlugLoginIF::~AidPlugLoginIF()
{
	if (NULL != m_pPlugLogin) {
		delete m_pPlugLogin;
		m_pPlugLogin = NULL;
	}
}
/* EOF */
