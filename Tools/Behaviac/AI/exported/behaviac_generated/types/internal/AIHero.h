﻿// -------------------------------------------------------------------------------
// THIS FILE IS ORIGINALLY GENERATED BY THE DESIGNER.
// YOU ARE ONLY ALLOWED TO MODIFY CODE BETWEEN '///<<< BEGIN' AND '///<<< END'.
// PLEASE MODIFY AND REGENERETE IT IN THE DESIGNER FOR CLASS/MEMBERS/METHODS, ETC.
// -------------------------------------------------------------------------------

#ifndef _BEHAVIAC_AIHERO_H_
#define _BEHAVIAC_AIHERO_H_

#include "behaviac_headers.h"

///<<< BEGIN WRITING YOUR CODE FILE_INIT

///<<< END WRITING YOUR CODE

class AIHero : public behaviac::Agent
///<<< BEGIN WRITING YOUR CODE AIHero
///<<< END WRITING YOUR CODE
{
public:
	AIHero();
	virtual ~AIHero();

	BEHAVIAC_DECLARE_AGENTTYPE(AIHero, behaviac::Agent)

	public: behaviac::string name;

	private: int p1;

	public: void SayHello();

///<<< BEGIN WRITING YOUR CODE CLASS_PART

///<<< END WRITING YOUR CODE
};

///<<< BEGIN WRITING YOUR CODE FILE_UNINIT

///<<< END WRITING YOUR CODE

#endif