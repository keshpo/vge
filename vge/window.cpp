#include "window.h"
#include "ui_window.h"


Window::Window(QWidget *parent) :
    QMainWindow(parent)
{
    area = new RenderArea(this);
    area->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setCentralWidget(area);



    firstColor = new QColor(qRgb(0, 0, 0));
    secondColor = new QColor(qRgb(255, 255, 255));
    firstColorWidget = new ColorWidget(*firstColor ,this);
    secondColorWidget = new ColorWidget(*secondColor,this);

    QMenu *fileMenu = new QMenu("&File", this);

    fileMenu->addAction(QIcon("://icons/new_icon.png"),
                        "&New...",
                        this,
                        SLOT(createFile()),
                        QKeySequence("Ctrl+N"));

    fileMenu->addAction(QIcon("://icons/open_icon.png"),
                        "&Open...",
                        this,
                        SLOT(openFile()),
                        QKeySequence("Ctrl+O"));

    fileMenu->addAction(QIcon("://icons/save_icon.png"),
                        "&Save...",
                        area ,
                        SLOT(saveFile()),
                        QKeySequence("Ctrl+S"));

    fileMenu->addSeparator();

    fileMenu->addAction("E&xit",
                        this,
                        SLOT(close()),
                        QKeySequence::Quit);

    menuBar()->addMenu(fileMenu);

    QMenu *toolsMenu = new QMenu ("&Tools", this);

    QAction *mouseAction = toolsMenu->addAction(QIcon("://icons/kursor.png"),"C&ursor");
    QAction *movingAction = toolsMenu->addAction(QIcon("://icons/hand_icon.png"), "&Move");
    QAction *fillingAction = toolsMenu->addAction(QIcon("://icons/filling_icon.png"), "Fi&ling");
    QMenu *choiceFigureAction = new QMenu ("F&igure", toolsMenu);

    QAction *circleAction = choiceFigureAction->addAction(QIcon("://icons/круг.png"),"Ellipse");
    QAction *squareAction = choiceFigureAction->addAction(QIcon("://icons/квадрат.png"),"Square");
    QAction *lineAction = choiceFigureAction->addAction(QIcon("://icons/линия.png"),"Line");
    QAction *polygonAction = choiceFigureAction->addAction(QIcon("://icons/полигон.png"),"Polygon");
    QAction *rhombAction = choiceFigureAction->addAction(QIcon("://icons/ромб.png"),"Rhomb");

    toolsMenu->addMenu(choiceFigureAction);

    QAction *addTextAction = toolsMenu->addAction(QIcon("://icons/текст.png"), "&Text");

    menuBar()->addMenu(toolsMenu);

    QMenu *helpMenu = new QMenu ("&Help");

    helpMenu->addAction("&About...",
                        this,
                        SLOT(aboutVge()),
                        QKeySequence("Ctrl+A"));

    menuBar()->addMenu(helpMenu);

    QSpinBox *spin;
    spin = new QSpinBox (this);
    spin->setRange(1, 4);
    spin->setValue(1);

    //QComboBox *lineType;
    //lineType = new QComboBox (this);

    QToolBar *tools = new QToolBar("Tools", this);
    tools->setMovable(false);
    addToolBar(Qt::LeftToolBarArea, tools);
    tools->addAction(mouseAction);
    tools->addAction(movingAction);
    tools->addAction(fillingAction);
    tools->addAction(addTextAction);
    tools->addAction(circleAction);
    tools->addAction(squareAction);
    tools->addAction(lineAction);
    tools->addAction(polygonAction);
    tools->addAction(rhombAction);
    tools->addWidget(firstColorWidget);
    tools->addWidget(secondColorWidget);
    tools->addSeparator();
    tools->addWidget(spin);

    connect(spin,SIGNAL(valueChanged(int)),area,SLOT(setPenSize(int)));

    connect(circleAction, SIGNAL(triggered()), area, SLOT(Ellipse()));
    connect(squareAction, SIGNAL(triggered()), area, SLOT(Square()));
    connect(lineAction, SIGNAL(triggered()), area, SLOT(Line()));
    connect(polygonAction, SIGNAL(triggered()), area, SLOT(Polygon()));
    connect(rhombAction, SIGNAL(triggered()), area, SLOT(Rhomb()));

    setWindowTitle(QString("VGE"));
    resize(640, 480);
}

Window::~Window()
{
}

void Window::createFile()
{

}

void Window::openFile(const QString &path)
{
    QString pathToFile;
    if(path.isNull()){
        pathToFile = QFileDialog::getOpenFileName(this, tr("Open file"),"","SVG file (*.*)");
    }
    else
        pathToFile = path;

    if (!pathToFile.isEmpty()){
        QFile svgFile(pathToFile);
        if (!svgFile.exists()){
            QMessageBox::critical(this, "Open fule", QString("Could not open file '%1'.").arg(pathToFile));
            return;
        }

        area->openFile(svgFile);
        //area->load(svgFile.fileName());

        setWindowTitle(QString("%1 - VGE").arg(pathToFile));

        //area->show();
        //resize(area->sizeHint() + QSize(80, 80 + menuBar()->height()));
    }
}

//void Window::saveFile(){}

void Window::aboutVge()
{
    QMessageBox::about(this, "About VGE", "Vector graphics editor for \ncreating and processing SVG files.");
}

void Window::setColor()
{
    //*color = QColorDialog::getColor(*color,this,"Color",0);
    //colorIcon = new QPixmap(32, 32);
   // colorIcon->fill(*color);
  //  colorSelect->setIcon(QIcon(*colorIcon));
//мб виджет?

   // if (newColor.isValid())
     //   scribbleArea->setPenColor(newColor);
}



