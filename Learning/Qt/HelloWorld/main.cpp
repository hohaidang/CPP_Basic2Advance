#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv); // default declaration of Qt
    QLabel *label = new QLabel("HelloWorld");
    label->setWindowTitle("My APP");
    label->resize(400, 400);
    label->show();
    return app.exec(); // Execute app
}
