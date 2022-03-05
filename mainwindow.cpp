#include "mainwindow.h"
#include "ui_mainwindow.h"
static const QString TEMPERANCE {"TEMPERANCE. Eat not to dullness; drink not to elevation.\n"
    "节制：食不过饱，饮不过量。"
};
static const QString SILENCE{"SILENCE. Speak not but what may benefit others or yourself; avoid trifling conversation.\n"
    "缄默：只说对人对己有益的话，避免闲聊。"};
static const QString ORDER{"ORDER. Let all your things have their places; let each part of your business have its time.\n"
    "秩序：物归其位，事有定期"};
static const QString RESOLUTION{"RESOLUTION. Resolve to perform what you ought; perform without fail what you resolve.\n"
    "决心：该做的事情一定要做，要做的事情一定做好。"};
static const QString FRUGALITY{"FRUGALITY. Make no expense but to do good to others or yourself; i.e., waste nothing.\n"
    "节俭：只为对人对己有益的事情买单，即不要浪费。"};
static const QString INDUSTRY{"INDUSTRY. Lose no time; be always employ’d in something useful; cut off all unnecessary actions.\n"
    "勤勉：不要浪费时间，只做有用的事情，戒除一切不必要的行为。"};
static const QString SINCERITY{"SINCERITY. Use no hurtful deceit; think innocently and justly, and, if you speak, speak accordingly.\n"
    "诚恳：不要恶意欺骗人，思想纯洁公正，讲话也是如此。"};
static const QString JUSTICE{"JUSTICE. Wrong none by doing injuries, or omitting the benefits that are your duty.\n"
    "正义：不做伤害别人的事情，做有益的事情是你的责任。"};
static const QString MODERATION{"MODERATION. Avoid extreams; forbear resenting injuries so much as you think they deserve.\n"
    "中庸：不走极端。对别人的伤害保持隐忍，将此视为应得之事。"};
static const QString CLEANLINESS{"CLEANLINESS. Tolerate no uncleanliness in body, cloaths, or habitation.\n"
    "清洁：身体、衣服及住所，力求整洁。"};
static const QString TRANQUILLITY{"TRANQUILLITY. Be not disturbed at trifles, or at accidents common or unavoidable.\n"
    "平静：不要被琐事、普通或者不可避免的事所扰。"};
static const QString CHASTITY{"CHASTITY. Rarely use venery but for health or offspring, never to dulness, weakness, or the injury of your own or another’s peace or reputation.\n"
    "贞节：仅为健康或生育的目的进行房事。爱惜身体，不要损害自己或他人的安宁与名誉。"};
static const QString HUMILITY{"HUMILITY. Imitate Jesus and Socrates.\n"
    "谦虚：向苏格拉底和耶稣学习。"};
static const QString My_MIND{"My intention being to acquire the habitude of all these virtues, I judg’d it would be well not to distract my attention by attempting the whole at once, but to fix it on one of them at a time; and, when I should be master of that, then to proceed to another, and so on, till I should have gone thro’ the thirteen; and, as the previous acquisition of some might facilitate the acquisition of certain others, I arrang’d them with that view, as they stand above. Temperance first, as it tends to procure that coolness and clearness of head, which is so necessary where constant vigilance was to be kept up, and guard maintained against the unremitting attraction of ancient habits, and the force of perpetual temptations. This being acquir’d and establish’d, Silence would be more easy; and my desire being to gain knowledge at the same time that I improv’d in virtue, and considering that in conversation it was obtain’d rather by the use of the ears than of the tongue, and therefore wishing to break a habit I was getting into of prattling, punning, and joking, which only made me acceptable to trifling company, I gave Silence the second place.\n\n"
    "我的目的是想养成这一切美德的习惯，所以我认为，为了不至于分散注意力，最好还是不要立刻全面去尝试，而是在一段时期内集中精力于其中某一个。当我掌握了那项美德之后，接着再开始注意另外一项，如此这样，直到我做到了13条为止。因为先获得的一些美德可以方便其他美德的培养，所以我就按照这个主张把它们排列起来，就像上面的次序那样。“节制”被我放在第一位，因为它可以使我保持头脑冷静和思想清楚。为了保持经常性的警惕，抵抗旧习惯不断的吸引力和无穷无尽的诱惑力，这种冷静的头脑和清晰的思想是大有必要的。在获得和养成了这项美德之后，养成“沉默”的美德就容易得多了。在改进品德的同时，我还想增进知识；而且我认为，在谈话时与其用嘴，还不如用耳朵更能增进知识，因此我想打破我当时正在形成的喜欢喋喋不休、爱说俏皮话、喜欢开玩笑的习惯，这种习惯只能使我和轻浮的人为伍，因此我将“沉默”放在第二位。"};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    virtueList.push_back(TEMPERANCE);
    virtueList.push_back(SILENCE);
    virtueList.push_back(ORDER);
    virtueList.push_back(RESOLUTION);
    virtueList.push_back(FRUGALITY);
    virtueList.push_back(INDUSTRY);
    virtueList.push_back(SINCERITY);
    virtueList.push_back(JUSTICE);
    virtueList.push_back(MODERATION);
    virtueList.push_back(CLEANLINESS);
    virtueList.push_back(TRANQUILLITY);
    virtueList.push_back(CHASTITY);
    virtueList.push_back(HUMILITY);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    changedTextForDate(QDate::currentDate());
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::changedTextForDate);
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged, this, &MainWindow::changedText);
    connect(ui->calendarWidget, &QCalendarWidget::currentPageChanged, this, &MainWindow::changedText);
    connect(ui->calendarWidget, &QCalendarWidget::activated, this, &MainWindow::changedText);

    connect(ui->curDateBtn, &QPushButton::clicked, [ = ]() {
        ui->calendarWidget->setSelectedDate(QDate::currentDate());
    });

    connect(ui->pushButton, &QPushButton::clicked, [ = ]() {
        int row = ui->tableWidget->rowCount() + 1;
        ui->tableWidget->setRowCount(row);
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QTime::currentTime().toString());
        ui->tableWidget->setVerticalHeaderItem(row - 1, item);
        for (int i = 0; i < virtueList.size(); ++i) {
            QTableWidgetItem *it = new QTableWidgetItem;
            ui->tableWidget->setItem(row - 1, i, it);
        }

    });

    connect(ui->pushButton_2, &QPushButton::clicked, [ = ]() {
        auto it = ui->tableWidget->currentItem();
        if (it) {
            ui->tableWidget->removeRow(it->row());
        }
    });


    ui->statusBar->addWidget(&statusLable);

    connect(ui->tableWidget, &QTableWidget::clicked, [ = ](const QModelIndex & index) {
        statusLable.setText(virtueList[index.column()]);
    });

    connect(ui->tableWidget, &QTableWidget::currentItemChanged, [ = ](const QTableWidgetItem * item) {
        statusLable.setText(virtueList[item->column()]);
    });


    connect(ui->pushButton_3, &QPushButton::clicked, [ & ]() {
        this->now -= QDate::currentDate().weekNumber();
        changedTextForDate(QDate::currentDate());
    });


    initDataBase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changedText()
{
    changedTextForDate(ui->calendarWidget->selectedDate());
}

void MainWindow::changedTextForDate(const QDate &date)
{
    int i = (date.weekNumber() + now) % virtueList.size();
    if(i<0){
        i = virtueList.size() - i;
        i=i%virtueList.size();
        i = virtueList.size()-i;

    }
    ui->textEdit->setText(this->virtueList[i]);
    ui->textEdit->append("\n");
    ui->textEdit->append(My_MIND);
}

bool MainWindow::initDataBase()
{

}


