#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QScreen>
#include <QDesktopWidget>
#include <QTransform>

class MovingImage : public QMainWindow {
    Q_OBJECT

public:
    MovingImage(QWidget *parent = nullptr)
        : QMainWindow(parent), dx(5), dy(5), angle(0) {
        // Set up the window
        setAttribute(Qt::WA_TranslucentBackground, true);
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

        // Load the PNG image
        label = new QLabel(this);
        QPixmap pixmap("image.png"); // Use the correct relative path
        originalPixmap = pixmap;
        label->setPixmap(pixmap);
        label->setFixedSize(pixmap.size());

        // Start a timer for the animation
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MovingImage::updateAnimation);
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
    void updateAnimation() {
        moveImage();  // Move the image
        rotateImage(); // Rotate the image
    }

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

    void rotateImage() {
        // Update rotation angle
        angle += 5; // Rotate by 5 degrees per tick
        if (angle >= 360) angle = 0; // Reset after full rotation

        // Apply the rotation transformation
        QTransform transform;
        transform.rotate(angle);
        QPixmap rotatedPixmap = originalPixmap.transformed(transform, Qt::SmoothTransformation);

        // Update the label with the rotated image
        label->setPixmap(rotatedPixmap);
    }

private:
    QLabel *label;
    QTimer *timer;
    int x, y; // Current position
    int dx, dy; // Movement deltas
    int angle; // Rotation angle
    QPixmap originalPixmap; // Original image for rotation
    QRect screenGeometry; // Screen geometry
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MovingImage window;
    window.show();

    return app.exec();
}
#include "main.moc"

