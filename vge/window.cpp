#include "window.h"
#include "ui_window.h"
#include <QtWidgets>
#include <QtSvg>
#include <QSvgRenderer>
#include <renderarea.h>

Window::Window(QWidget *parent) :
    QMainWindow(parent)
{
    QMenu *fileMenu = new QMenu("File", this);
    QAction *openFileAction = fileMenu->addAction("Open...");

    menuBar()->addMenu(fileMenu);

    connect(openFileAction, SIGNAL(triggered()), this, SLOT(openFile()));
    ui->setupUi(this);
}

Window::~Window()
{
    //delete ui;
}

void Window::openFile(const QString &path)
{
    QString pathToFile;
    if(path.isNull()){
        pathToFile = QFileDialog::getOpenFileName(this, tr("Open file"),"","SVG file (*.svg)");
    }
    else
        pathToFile = path;

    QFile file(pathToFile,this);
    QSvgWidget *svg = new QSvgWidget(file.fileName(),this);

    svg->show();



    //setCentralWidget();
    //QSvgRenderer *ren = svg.renderer();
}
