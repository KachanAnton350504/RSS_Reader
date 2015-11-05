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

bool Saver::isContain(QString str)
{
    QString tmp;
    bool isContain = false;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(0,"Ошибка открытия файла", "Проверьте наличие файла для чтения");
    }
    else
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            tmp = in.readLine();
            if(tmp == str)
            {
                isContain = true;
            }
            else
            {
               isContain = false;
            }
        }
        file.close();
    }
    return isContain;
}

void Saver::deleteFileFeed(QString str)
{
    QString tmpStr;
    QFile tmpFile("D:\\tmp.txt");
    if(!tmpFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(0,"Ошибка открытия файла", "Проверьте наличие файла для записи");
    }
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(0,"Ошибка открытия файла", "Проверьте наличие файла для чтения");
    }
    else
    {
        QTextStream in(&file);
        QTextStream out(&tmpFile);
        while(!in.atEnd())
        {
            tmpStr = in.readLine();
            if(tmpStr != str)
            {
                out << tmpStr << "\n";
            }
        }
        file.close();
        tmpFile.close();
    }
    if(!tmpFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(0,"Ошибка открытия файла", "Проверьте наличие файла для записи");
    }
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(0,"Ошибка открытия файла", "Проверьте наличие файла для чтения");
    }
    else
    {
        QTextStream in(&tmpFile);
        QTextStream out(&file);
        while(!in.atEnd())
        {
            tmpStr = in.readLine();
            out << tmpStr << "\n";
        }
        file.close();
        tmpFile.close();
    }
}
