#ifndef CLASSIC_COMICS_VIEW_H
#define CLASSIC_COMICS_VIEW_H

#include "comics_view.h"

#include <QModelIndex>
#include <QModelIndexList>

class YACReaderTableView;
class QSplitter;
class ComicFlowWidget;
class QToolBar;
class ComicModel;
class QStackedWidget;

class ClassicComicsView : public ComicsView
{
    Q_OBJECT
public:
    ClassicComicsView(QWidget *parent = 0);
    void setToolBar(QToolBar * toolBar);
    void setModel(ComicModel *model);
    void setCurrentIndex(const QModelIndex &index);
    QModelIndex currentIndex();
    QItemSelectionModel * selectionModel();
    void scrollTo(const QModelIndex & mi, QAbstractItemView::ScrollHint hint );
    void toFullScreen();
    void toNormal();
    void updateConfig(QSettings * settings);
    void enableFilterMode(bool enabled);
    void selectIndex(int index);

public slots:
    void centerComicFlow(const QModelIndex & mi);
    void updateTableView(int i);
    void saveTableHeadersStatus();
    void saveSplitterStatus();
    void applyModelChanges(const QModelIndex & topLeft,const QModelIndex & bottomRight,const QVector<int> & roles);
    void removeItemsFromFlow(const QModelIndex & parent, int from, int to);
    //ComicsView
    void setShowMarks(bool show);
    void selectAll();
    void selectedComicForOpening(const QModelIndex & mi);

protected slots:
    void requestedViewContextMenu(const QPoint & point);
    void requestedItemContextMenu(const QPoint & point);

private:
    YACReaderTableView * tableView;
    QWidget *comics;
    QSplitter * sVertical;
    ComicFlowWidget * comicFlow;
    QSettings * settings;
    void closeEvent ( QCloseEvent * event );

    QStackedWidget * stack;

    QByteArray previousSplitterStatus;
    QWidget * searchingIcon;
    bool searching;
    void setupSearchingIcon();
    void showSearchingIcon();
    void hideSearchingIcon();
    void updateSearchingIconPosition();
};

#endif // CLASSIC_COMICS_VIEW_H