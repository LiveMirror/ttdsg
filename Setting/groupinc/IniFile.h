/************************************************************************
   T h e   O p e n   W i n d o w s   P r o j e c t
 ------------------------------------------------------------------------
   Filename   : IniFile.h
   Author(s)  : Carsten Breuer
 ------------------------------------------------------------------------
 Copyright (c) 2000 by Carsten Breuer (CBreuer@openwin.de)
/************************************************************************/

#ifndef INIFILE_H
#define INIFILE_H
#pragma warning (disable:4996)	//È¡Ïû¾¯¸æ

/*
#ifndef OWP_DONT_DEF_FALSE
#ifndef FALSE
#define FALSE 0
#endifIniFile.h 
#endif

#ifndef OWP_DONT_DEF_TRUE
#ifndef TRUE
#define TRUE 1
#endif
#endif


#ifndef OWP_DONT_DEF_bool
#ifndef bool
#define bool unsigned int
#endif
#endif

#ifndef OWP_DONT_DEF_CCHR
#ifndef const char
#define const char const char
#endif
#endif

#ifndef OWP_DONT_DEF_UCHR
#ifndef UCHR
#define UCHR unsigned char
#endif
#endif

#ifndef OWP_DONT_DEF_UCCHR
#ifndef UCCHR
#define UCCHR const unsigned char
#endif
#endif

#ifndef OWP_DONT_DEF_UINT
#ifndef UINT
#define UINT unsigned int
#endif
#endif

#ifndef OWP_DONT_DEF_WORD
#ifndef WORD
#define WORD unsigned short
#endif
#endif

#ifdef LINUX // Remove CR, on unix systems.
#define INI_REMOVE_CR
#define DONT_HAVE_STRUPR
#endif
*/

#define tpNULL       0
#define tpSECTION    1
#define tpKEYVALUE   2
#define tpCOMMENT    3

#define TCHAR_DEFAULT		_T("Default")
#define BOOL_DEFAULT		FALSE
#define INT_DEFAULT			0
#define DOUBLE_DEFAULT		0.0

struct ENTRY
{
   char   Type;
   char  *pText;
   struct ENTRY *pPrev;
   struct ENTRY *pNext;
};

typedef struct
{
   struct ENTRY *pSec;
   struct ENTRY *pKey;
   char          KeyText [128];
   char          ValText [128];
   char          Comment [255];
} EFIND;

/* Macros */
#define ArePtrValid(Sec,Key,Val) ((Sec!=NULL)&&(Key!=NULL)&&(Val!=NULL))

class CIniFile
{
public:
            CIniFile    (void);
            ~CIniFile   (void);
    UINT    GetVersion  (void);
    bool    OpenIniFile (const char *pFileName);
    bool    ReadBool    (const char *pSection, const char *pKey, bool   Default);
    int     ReadInt     (const char *pSection, const char *pKey, int    Default);
    double  ReadDouble  (const char *pSection, const char *pKey, double Default);
    const char    *ReadString (const char *pSection, const char *pKey, const char  *pDefault);

    void    WriteBool   (const char *pSection, const char *pKey, bool   Value);
    void    WriteInt    (const char *pSection, const char *pKey, int    Value);
    void    WriteDouble (const char *pSection, const char *pKey, double Value);
    void    WriteString (const char *pSection, const char *pKey, const char  *pValue);

    void    CloseIniFile ();
    bool    WriteIniFile (const char *pFileName);
	bool	DeleteKey (const char *pSection, const char *pKey);

protected:
	
	struct  ENTRY *m_pEntry;
	struct  ENTRY *m_pCurEntry;
	char    m_result [255];
	FILE    *m_pIniFile;
	void    AddKey     (struct ENTRY *pEntry, const char *pKey, const char *pValue);
	bool    AddItem    (char Type, const char *pText);
	bool    AddItemAt (struct ENTRY *pEntryAt, char Mode, const char *pText);
	void    FreeMem    (void *pPtr);
	void    FreeAllMem (void);
	bool    FindKey    (const char *pSection, const char *pKey, EFIND *pList);
	bool    AddSectionAndKey (const char *pSection, const char *pKey, const char *pValue);
	struct  ENTRY *MakeNewEntry (void);
	struct  ENTRY *FindSection (const char *pSection);
};

#endif