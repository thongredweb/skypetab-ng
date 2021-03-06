#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QList>
#include <QTabWidget>
#include <QSplitter>
#include "stwindowcontainer.h"
#include "contactlistcontainer.h"
#include "stwatcher.h"


namespace skypetab
{

class STabMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit STabMainWindow(QWidget *parent = 0);
    ~STabMainWindow();
	STWindowContainer *AddTab(QWidget *tab, bool activate);
	void SetMainWindow(QWidget *tab);
	bool hasActiveTab();
	void toggleContacts();
	bool activateTab(QWidget *widget);
	static bool tryActivatePreviousInstance ();
protected:
	void timerEvent(QTimerEvent*);
	virtual void resizeEvent(QResizeEvent *event);
	bool contactsHidden();
	virtual void closeEvent(QCloseEvent *);
	bool eventFilter(QObject*obj, QEvent*ev);
	void setVisible(bool visible);
	void changeEvent(QEvent *);
	bool x11Event(XEvent *ev);
private:
	QWidget*_focusTrap;
	QTabWidget* _tabs;
	ContactListContainer* _contacts;
	QSplitter*_splitter;
	QList<STWatcher*> _watchers;
	QList<int> getSizes(bool contactsHidden, QSize *newSize=0);
	int findTab(QWidget*widget);

private slots:
	void tabChanged (int index);
	void tabChangedAfterShock();
	void tabCloseRequested(int index);
};

}
#endif // MAINWINDOW_H
