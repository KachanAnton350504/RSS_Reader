//#include ".h"

Saver::Saver(QObject *parent) : QObject(parent)
{
    file.setFileName("D:/Projects/RSS_Reader/resourse/files/address_feed.txt");
}

void Saver::addLink(QString str)
{
    if(!file.open(QFile::Append | QFile::Text))
    {
        QMessageBox::information(0,"Ошибка открытия файла ", "Проверьте наличие файла для записи");
    }
    else
    {
        QTextStream out(&file);
        out << str << "\n";
        file.close();
    }
}

QStringList Saver::readLink()
{
    QStringList list;
    QString str ;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(0,"Ошибка открытия файла", "Проверьте наличие файла для чтения");
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            str = in.readLine();
            list.append(str);
        }
        file.close();
    }
    return list;
}
