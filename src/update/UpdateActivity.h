/*
 * UpdateActivity.h
 *
 *  Created on: Jun 20, 2012
 *      Author: Simon
 */

#ifndef UPDATEACTIVITY_H_
#define UPDATEACTIVITY_H_

#include "interface/Window.h"
#include "tasks/TaskWindow.h"

class UpdateActivity {
	Task * updateDownloadTask;
	TaskWindow * updateWindow;
public:
	UpdateActivity();
	virtual ~UpdateActivity();
	virtual void NotifyDone(Task * sender);
};

#endif /* UPDATEACTIVITY_H_ */