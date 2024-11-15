#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QMovie>
#include <QWidget>
#include <QScreen>
#include <QDesktopWidget>
#include <QtCore>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the main window
    QMainWindow window;

    // Make the window transparent and always on top
    window.setAttribute(Qt::WA_TranslucentBackground, true);
    window.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // Create a central widget and set a layout
    QWidget *centralWidget = new QWidget(&window);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Add an animated GIF
    QLabel *label = new QLabel(centralWidget);
    QMovie *movie = new QMovie("../gif/joker.gif");  // Relative path from the executable location
    label->setMovie(movie);
    movie->start();
    layout->addWidget(label);

    window.setCentralWidget(centralWidget);

    // Resize the window to fit the GIF
    window.setFixedSize(movie->currentPixmap().size());

    // Move the window to the right side corner
    QRect screenGeometry = QApplication::primaryScreen()->geometry();
    QRect windowGeometry = window.geometry();
    int rightX = screenGeometry.width() - windowGeometry.width();  // X position for right side
    int bottomY = screenGeometry.height() - windowGeometry.height();  // Y position for bottom
    window.move(rightX, bottomY);

    window.show();

    // Start the event loop
    return app.exec();
}

