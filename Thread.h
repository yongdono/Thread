#ifndef THREAD_H
#define THREAD_H

#include "Common.h"

#ifdef WINDOWS
//typedef unsigned long DWORD;
typedef HANDLE THREAD_HANDLE;
#else
typedef unsigned long DWORD;
typedef pthread_t THREAD_HANDLE;
typedef void* LPVOID;
#endif

class CThread
{
public:
	CThread();
	virtual ~CThread();
	bool Create(void);
	virtual bool ExitInstance();
	virtual bool InitInstance();
	virtual void Run();
	bool Join();
	void SleepMs(int ms);
	THREAD_HANDLE GetHandle();

#ifdef WINDOWS
	static DWORD WINAPI _ThreadEntry(LPVOID pParam);
#else
	static void * _ThreadEntry(void *pParam);
#endif

private:
	THREAD_HANDLE  m_hThread;
	DWORD m_IDThread;

};

#endif
