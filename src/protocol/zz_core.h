/******************************************************************************/ 
/*  This is the open source project which has GNU GNU GENERAL PUBLIC LICENSE  */
/*	        The developers are Aram Hakhverdyan and Levon Gasparyan.          */
/******************************************************************************/

/*
	File: 
		zz_core.h
	Abstract:
		Defines the main protocol concepst to work with the low-level layer
*/

#ifndef ZZ_CORE_H
#define ZZ_CORE_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
//
//  STD includes
//
#include <stdexcept>
#include <new>

//
//	Qt includes
//
#include <QObject>
#include <QMetaType>
#include <QPair>
#include <QString>
#include <QList>
#include <QMap>
#include <QVector>
#include <QSet>
#include <QHash>
#include <QStack>
#include <QQueue>
#include <QByteArray>
#include <QBitArray>
#include <QLinkedList>
#include <QStringList>
#include <QVariant>
#include <QDateTime>
#include <QDataStream>
#include <QTextStream>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace zz { // ZavZag :P
////////////////////////////////////////////////////////////////////////////////

//
//	Request Types
//
enum class ERequestType
{
	Undefined = 0,
	Register,
	Login,
	Logout,
	Lookup,
	Friend,
	ShowMessaging,
	SettingsChanged,
	SendMessage,
	Unregister
};

//
//	Request Status
//
enum class ERequestStatus
{
	Unknown = 0,
	Succeeded,
	Failed,
	Canceled
};
////////////////////////////////////////////////////////////////////////////////
} // namespace zz
////////////////////////////////////////////////////////////////////////////////

#endif // ZZ_CORE_H
/* end of file */
