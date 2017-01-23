/*
 * Copyright (c) 2017, Neo He <neohe2007 at gmail dot com>
 * All rights reserved
 */

#ifndef common_def_h
#define common_def_h

#define DECLARE_SINGLETON(CLASS)\
public:\
    static CLASS* Instance();\
private:\
    CLASS();\
    ~CLASS();\
    CLASS(const CLASS &);\
    CLASS &operator= (const CLASS &);\
    static CLASS *m_pInstance;

#endif /* common_def_h */
