/*
 * PreviewModel.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: Simon
 */

#include "PreviewModel.h"
#include "client/Client.h"

PreviewModel::PreviewModel():
	save(NULL),
	savePreview(NULL),
	doOpen(false)
{
	// TODO Auto-generated constructor stub

}

void PreviewModel::UpdateSave(int saveID, int saveDate)
{
	save = Client::Ref().GetSave(saveID, saveDate);
	notifySaveChanged();
	savePreview = Client::Ref().GetPreview(saveID, saveDate);
	notifyPreviewChanged();
}

void PreviewModel::SetDoOpen(bool doOpen)
{
	this->doOpen = doOpen;
}

bool PreviewModel::GetDoOpen()
{
	return doOpen;
}

Thumbnail * PreviewModel::GetPreview()
{
	return savePreview;
}

Save * PreviewModel::GetSave()
{
	return save;
}

void PreviewModel::notifyPreviewChanged()
{
	for(int i = 0; i < observers.size(); i++)
	{
		observers[i]->NotifyPreviewChanged(this);
	}
}

void PreviewModel::notifySaveChanged()
{
	for(int i = 0; i < observers.size(); i++)
	{
		observers[i]->NotifySaveChanged(this);
	}
}

void PreviewModel::AddObserver(PreviewView * observer) {
	observers.push_back(observer);
	observer->NotifyPreviewChanged(this);
	observer->NotifySaveChanged(this);
}

PreviewModel::~PreviewModel() {
	if(save)
		delete save;
	if(savePreview)
		delete savePreview;
}
