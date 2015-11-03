RSS-READER  ДЛЯ ОС  WINDOWS

1 Введение

Во введении описывается контекст проекта. Определить название продукта. В общих чертах описать, что продукт будет делать и чего он делать не будет (определить границы проекта)


Исходные данные к проекту:

Клиентска программа для автоматического сбора сообщений из источников, экспортирующих в формат RSS, а именно заголовков новостей. Просмотр новостей возможен в самой программе посредством встроенного в него браузера. Программа автоматически обновляет новостную ленту каждые пол часа, так же предусмотрена возможность ручного обновления лент пользователем. Пользователь может добавлять/удалять каналы во время работы программы Программа имеет удобный пользовательский интерфейс. Производится обработка исключительных ситуаций.


2 Требования пользователя

2.1 Программные интерфейсы

Так как существует несколько видов RSS-ридеров, есть возможность различной реализации: создание отдельного сайта, расширения для браузера или клиентской программы. В данном проекте был выбран способ реализации клиентской программы. Суть его заключается в том, что программа получает на вход адрес новостного канала, затем она генерирует HTTP запрос, после этого данные, которые приходят в результате запроса, она должна расшифровать и предоставить в удобном формате для пользователя. Кроме этого программа должна иметь удобный пользовательский интерфейс. Построение удобного пользовательского интерфейса это задача сама по себе достаточно сложная. Для ее решения всех поставленных задач в данном проекте будем использовать библиотеку Qt.

Qt — кроссплатформенный инструментарий разработки ПО на языке программирования С++.
Qt позволяет запускать написанное с его помощью ПО в большинстве современных операционных систем, путём простой компиляции программы для каждой ОС без изменения исходного кода. Включает в себя все основные классы, которые могут потребоваться при разработке прикладного программного обеспечения, начиная от элементов графического интерфейса и заканчивая классами для работы с сетью, базами данных и XML. Qt является полностью объектно-ориентированным, легко расширяемым и поддерживающим технику компонентного программирования.

Отличительная особенность Qt от других библиотек — использование Meta Object Compiler (MOC) — предварительной системы обработки исходного кода (в общем-то, Qt — это библиотека не для чистого C++, а для его особого наречия, с которого и «переводит» MOC для последующей компиляции любым стандартным C++ компилятором). MOC позволяет во много раз увеличить мощь библиотек, вводя такие понятия, как слоты и сигналы. Кроме того, это позволяет сделать код более лаконичным. Утилита MOC ищет в заголовочных файлах на C++ описания классов, содержащие макрос Q_OBJECT, и создаёт дополнительный исходный файл на C++, содержащий метаобъектный код.

Qt позволяет создавать собственные плагины и размещать их непосредственно в панели визуального редактора. Также существует возможность расширения привычной функциональности виджетов, связанной с размещением их на экране, отображением, перерисовкой при изменении размеров окна.

Qt комплектуется визуальной средой разработки графического интерфейса ”Qt Designer”, позволяющей создавать диалоги и формы в режиме WYSIWYG. В поставке Qt есть“Qt Linguist” — графическая утилита, позволяющая упростить локализацию и перевод программы на многие языки; и “Qt Assistant” — справочная система Qt, упрощающая работу с документацией по библиотеке, а также позволяющая создавать кросс-платформенную справку для разрабатываемого на основе Qt ПО. Начиная с версии 4.5.0, в комплект Qt включена среда разработки “Qt Creator”, которая включает в себя редактор кода, справку, графические средства ”Qt Designer”и возможность отладки приложений. “Qt Creator” может использовать GCC или Microsoft VC++ в качестве компилятора и GDB в качестве отладчика. Для Windows версий библиотека комплектуется компилятором, заголовочными и объектными файлами MinGW.
Существуют версии библиотеки для Microsoft Windows, систем класса UNIX c графической подсистемой X11, Android, iOS, Mac Os X, Microsoft Windows CE, QNX, встраиваемых  Linux-систем и платформы S60. 

Компоненты библиотеки:

•	QtCore — классы ядра библиотеки, используемые другими модулями;

•	QtGui — компоненты графического интерфейса;

•	QtNetwork — набор классов для сетевого программирования. Поддержка различных высокоуровневых протоколов может меняться от версии к версии. В версии 4.2.x присутствуют классы для работы с протоколами FTP и HTTP. Для работы с протоколами TCP/IP предназначены такие классы, как QTcpServer, QTcpSocket для TCP и QUdpSocket для UDP;

•	QtOpenGL — набор классов для работы с OpenGL;

•	QtSql — набор классов для работы с базами данных с использованием языка структурированных запросов SQL. Основные классы данного модуля в версии 4.2.х: QSqlDatabase — класс для предоставления соединения с базой, для работы с какой-нибудь конкретной базой данных требует объект, унаследованный от класса QSqlDriver — абстрактного класса, который реализуется для конкретной базы данных и может требовать для компиляции SDK базы данных. Например, для сборки драйвера под базу данных Firebird/InterBase требует .h файлы и библиотеки статической линковки, входящие в комплект поставки данной БД;

•	QtScript — классы для работы с Qt Scripts;

•	QtSvg — классы для отображения и работы с данными Scalable Vector Graphics (SVG);

•	QtXml — модуль для работы с XML, поддерживается SAX и DOM модели работы;

•	QtDesigner — классы создания расширений QtDesigner’а для своих собственных виджетов;

•	QtUiTools — классы для обработки в приложении форм Qt Designer;

•	QtAssistant — справочная система;

•	Qt3Support — модуль с классами, необходимыми для совместимости с библиотекой Qt версии 3.х.х;

•	QtTest — модуль для работы с UNIT тестами;

•	QtWebKit — модуль WebKit, интегрированный в Qt и доступный через её классы;

•	QtXmlPatterns — модуль для поддержки XQuery 1.0 и XPath 2.0;

•	Phonon — модуль для поддержки воспроизведения и записи видео и аудио, как локально, так и с устройств и по сети;

•	QtCLucene — модуль для поддержки полнотекстового поиска, применяется в новой версии Assistant в Qt 4.4;

•	ActiveQt — модуль для работы с ActiveX и COM технологиями для Qt-разработчиков под Windows.

•	QtDeclarative — модуль, предоставляющий декларативный фреймворк для создания динамичных, настраиваемых пользовательских 
интерфейсов.

2.2 Интерфейс пользователя

Интерфейс будет максимально простым, для того, чтобы программой мог пользоваться любой пользователь.
Предполагается 2 поля. Одно со списком новостей, другое где их можно просматривать.
Чек-бокс для ввода адреса фида. 
Кнопки ADD/UPDATE/DELETE FEED

2.3 Характеристики пользователей

Из-за простоты программы ей могут пользоваться все пользователи. Так же уровень их образованности и уровень владения компьютером может быть минимальным, для понимания интерфейса ПО.

2.4 Предположения и зависимости

Основной фактор, который влияет на работоспособность программы – это наличие соединения компьютера с интернетом

3 Системные требования


• Операционная система: Windows XP / Vista / 7 / 8 / 8.1 / 10

• Процессор: Pentium 4 или более новый

• Оперативная память: 64 MB RAM

• Видеокарта: 32 MB VRAM

• Место на жестком диске: 100 MB


3.1 Функциональные требования

1. Принимает RSS-Feed HTML файл с сайта

2. Парсим этот HTML файл

Вывод актуальную информацию их этого HTML файла

3.2 Нефункциональные требования

1.  Не более 3-х кнопок на экране

2.  Актуальность представляемой информации.