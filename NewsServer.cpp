/*
 *  This file if part of nzbget
 *
 *  Copyright (C) 2004 Sven Henkel <sidddy@users.sourceforge.net>
 *  Copyright (C) 2007-2013 Andrey Prygunkov <hugbug@users.sourceforge.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * $Revision$
 * $Date$
 *
 */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32
#include "win32.h"
#endif

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "nzbget.h"
#include "NewsServer.h"

NewsServer::NewsServer(int iID, bool bActive, const char* szName, const char* szHost, int iPort,
	const char* szUser, const char* szPass, bool bJoinGroup, bool bTLS,
	const char* szCipher, int iMaxConnections, int iLevel, int iGroup)
{
	m_iID = iID;
	m_bActive = bActive;
	m_iPort = iPort;
	m_iLevel = iLevel;
	m_iNormLevel = iLevel;
	m_iGroup = iGroup;
	m_iMaxConnections = iMaxConnections;
	m_bJoinGroup = bJoinGroup;
	m_bTLS = bTLS;
	m_szHost = szHost ? strdup(szHost) : NULL;
	m_szUser = szUser ? strdup(szUser) : NULL;
	m_szPassword = szPass ? strdup(szPass) : NULL;
	m_szCipher = szCipher ? strdup(szCipher) : NULL;

	if (szName && strlen(szName) > 0)
	{
		m_szName = strdup(szName);
	}
	else
	{
		m_szName = (char*)malloc(20);
		snprintf(m_szName, 20, "server%i", iID);
		m_szName[20-1] = '\0';
	}
}

NewsServer::~NewsServer()
{
	if (m_szName)
	{
		free(m_szName);
	}
	if (m_szHost)
	{
		free(m_szHost);
	}
	if (m_szUser)
	{
		free(m_szUser);
	}
	if (m_szPassword)
	{
		free(m_szPassword);
	}
	if (m_szCipher)
	{
		free(m_szCipher);
	}
}
