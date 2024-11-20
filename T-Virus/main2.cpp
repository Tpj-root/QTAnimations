// Bouncing DVD Logo Animation
//
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QScreen>
#include <QDesktopWidget>

class MovingImage : public QMainWindow {
    Q_OBJECT

public:
    MovingImage(QWidget *parent = nullptr)
        : QMainWindow(parent), dx(5), dy(5) {
        // Set up the window
        setAttribute(Qt::WA_TranslucentBackground, true);
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

        // Load the PNG image
        label = new QLabel(this);
        QPixmap pixmap("image_0.png"); // Use the correct relative path
        label->setPixmap(pixmap);
        label->setFixedSize(pixmap.size());

        // Start a timer for the animation
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MovingImage::moveImage);
        timer->start(30); // Update every 30ms

        // Initial position
        x = 0;
        y = 0;

        // Get screen geometry
        screenGeometry = QApplication::primaryScreen()->geometry();

        // Resize the window to the size of the image
        setFixedSize(pixmap.size());
    }

private slots:
    void moveImage() {
        // Update the position
        x += dx;
        y += dy;

        // Check for collisions with the edges of the screen
        if (x <= 0 || x + label->width() >= screenGeometry.width()) {
            dx = -dx; // Reverse horizontal direction
        }
        if (y <= 0 || y + label->height() >= screenGeometry.height()) {
            dy = -dy; // Reverse vertical direction
        }

        // Move the label
        move(x, y);
    }

private:
    QLabel *label;
    QTimer *timer;
    int x, y; // Current position
    int dx, dy; // Movement deltas
    QRect screenGeometry; // Screen geometry
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MovingImage window;
    window.show();

    return app.exec();
}
#include "main.moc"


