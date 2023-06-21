#include <QApplication>
#include <QHBoxLayout>
#include <QWebEngineView>
#include <QPlainTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *window = new QWidget;
    window->resize(700,500);
    auto *layOut = new QHBoxLayout(window) ;
    auto *web = new QWebEngineView(nullptr);
    auto *editor = new QPlainTextEdit(nullptr);
    layOut->addWidget(editor,1);
    layOut->addWidget(web,1);
    QObject::connect(editor,&QPlainTextEdit::textChanged,[&web,&editor](){
        web->setHtml(editor->toPlainText());
    });
    window->show();
    return a.exec();
}
