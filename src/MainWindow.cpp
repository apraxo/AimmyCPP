#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , aimAssistActive(false)
{
    ui->setupUi(this);

    // Connect the sliders to their slots
    connect(ui->SensitivitySlider, &QSlider::valueChanged, this, &MainWindow::onSensitivityChanged);
    connect(ui->EMASlider, &QSlider::valueChanged, this, &MainWindow::onEMASmoothingChanged);
    connect(ui->FOVSlider, &QSlider::valueChanged, this, &MainWindow::onFOVChanged);
    connect(ui->DynamicFOVSlider, &QSlider::valueChanged, this, &MainWindow::onDynamicFOVChanged);
    connect(ui->JitterSlider, &QSlider::valueChanged, this, &MainWindow::onJitterChanged);
    connect(ui->YOffsetSlider, &QSlider::valueChanged, this, &MainWindow::onYOffsetChanged);
    connect(ui->XOffsetSlider, &QSlider::valueChanged, this, &MainWindow::onXOffsetChanged);
    connect(ui->AIFontSizeSlider, &QSlider::valueChanged, this, &MainWindow::onAiFontSizeChanged);
    connect(ui->BoxWidthSlider, &QSlider::valueChanged, this, &MainWindow::onBoxWidthChanged);
    connect(ui->OpacitySlider, &QSlider::valueChanged, this, &MainWindow::onOpacityChanged);
    connect(ui->AIConfidenceSlider, &QSlider::valueChanged, this, &MainWindow::onAIConfidenceChanged);

    // Connect the combo box to its slot
    connect(ui->PredictionMethodsDropdown, &QComboBox::currentTextChanged, this, &MainWindow::onPredictionMethodChanged);

    // Connect the checkboxes to their slots
    connect(ui->AimAssistToggle, &QCheckBox::toggled, this, &MainWindow::onAimAssistToggle);
    connect(ui->PredictionsToggle, &QCheckBox::toggled, this, &MainWindow::onPredictionsToggle);
    connect(ui->EMASmoothingToggle, &QCheckBox::toggled, this, &MainWindow::onEMASmoothingToggle);
    connect(ui->ShowFOVToggle, &QCheckBox::toggled, this, &MainWindow::onShowFOVToggle);
    connect(ui->UITopmostToggle, &QCheckBox::toggled, this, &MainWindow::onUITopmostToggle);

    // Set initial values
    ui->SensitivityValuesLabel->setText(QString::number(ui->SensitivitySlider->value()));
    ui->EMASmoothingValuesLabel->setText(QString::number(ui->EMASlider->value()));
    ui->FOVSizeValuesLabel->setText(QString::number(ui->FOVSlider->value()));
    ui->DynamicFOVSizeValuesLabel->setText(QString::number(ui->DynamicFOVSlider->value()));
    ui->JitterValuesLabel->setText(QString::number(ui->JitterSlider->value()));
    ui->YOffsetValuesLabel->setText(QString::number(ui->YOffsetSlider->value()));
    ui->XOffsetValuesLabel->setText(QString::number(ui->XOffsetSlider->value()));
    ui->AIFontSizeValuesLabel->setText(QString::number(ui->AIFontSizeSlider->value()));
    ui->BoxWidthValuesLabel->setText(QString::number(ui->BoxWidthSlider->value()));
    ui->OpacityValuesLabel->setText(QString::number(ui->OpacitySlider->value()));
    ui->AIConfidenceDisplay->display(QString::number(ui->AIConfidenceSlider->value()) + "%");

    // Initialize keybind event filters
    dynamicFOVKeybindFilter = new KeybindEventFilter(ui->DynamicFOVKeybind, this);
    outputBotActionKeybindFilter = new KeybindEventFilter(ui->OutputBotActionKeybind, this);
    botKeybindFilter = new KeybindEventFilter(ui->BotKeybind, this);
    aimKeybindFilter = new KeybindEventFilter(ui->AimKeybind, this);
    stopKeybindFilter = new KeybindEventFilter(ui->StopKeybind, this);

    connect(dynamicFOVKeybindFilter, &KeybindEventFilter::keySequenceChanged, this, &MainWindow::onDynamicFOVKeybindChanged);
    connect(outputBotActionKeybindFilter, &KeybindEventFilter::keySequenceChanged, this, &MainWindow::onOutputBotActionKeybindChanged);
    connect(botKeybindFilter, &KeybindEventFilter::keySequenceChanged, this, &MainWindow::onBotKeybindChanged);
    connect(aimKeybindFilter, &KeybindEventFilter::keySequenceChanged, this, &MainWindow::onAimKeybindChanged);
    connect(stopKeybindFilter, &KeybindEventFilter::keySequenceChanged, this, &MainWindow::onStopKeybindChanged);

    // Setup color buttons
    setupColorButtons();

    // Load configuration and model files
    loadConfigFiles();
    loadModelFiles();

    // Connect config and model list item clicks
    connect(ui->ConfigList, &QListWidget::itemClicked, this, &MainWindow::on_configList_itemClicked);
    connect(ui->ModelList, &QListWidget::itemClicked, this, &MainWindow::on_modelList_itemClicked);

    // Setup FOV display
    scene = new QGraphicsScene(this);
    fovCircle = new QGraphicsEllipseItem();
    scene->addItem(fovCircle);
    fovCircle->setVisible(false);

    // Initialize prediction method
    leadTargetPrediction = new LeadTargetPrediction();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dynamicFOVKeybindFilter;
    delete outputBotActionKeybindFilter;
    delete botKeybindFilter;
    delete aimKeybindFilter;
    delete stopKeybindFilter;
    delete leadTargetPrediction;
}

void MainWindow::onSensitivityChanged(int value)
{
    ui->SensitivityValuesLabel->setText(QString::number(value));
    // Add functionality to change sensitivity in Aimmy
}

void MainWindow::onEMASmoothingChanged(int value)
{
    ui->EMASmoothingValuesLabel->setText(QString::number(value));
    // Add functionality to change EMA smoothing in Aimmy
}

void MainWindow::onPredictionMethodChanged(const QString &method)
{
    // Change the prediction method in Aimmy
}

void MainWindow::onAimAssistToggle(bool checked)
{
    aimAssistActive = checked;
}

void MainWindow::onPredictionsToggle(bool checked)
{
    // Enable or disable predictions in Aimmy
}

void MainWindow::onEMASmoothingToggle(bool checked)
{
    // Enable or disable EMA smoothing in Aimmy
}

void MainWindow::onDynamicFOVKeybindChanged(const QString &keySequence)
{
    ui->DynamicFOVKeybind->setText(keySequence);
    // Add functionality to change the dynamic FOV keybind in Aimmy
}

void MainWindow::onOutputBotActionKeybindChanged(const QString &keySequence)
{
    ui->OutputBotActionKeybind->setText(keySequence);
    // Add functionality to change the output bot action keybind in Aimmy
}

void MainWindow::onBotKeybindChanged(const QString &keySequence)
{
    ui->BotKeybind->setText(keySequence);
    // Add functionality to change the bot keybind in Aimmy
}

void MainWindow::onAimKeybindChanged(const QString &keySequence)
{
    ui->AimKeybind->setText(keySequence);
    // Add functionality to change the aim keybind in Aimmy
}

void MainWindow::onStopKeybindChanged(const QString &keySequence)
{
    ui->StopKeybind->setText(keySequence);
    // Add functionality to change the stop keybind in Aimmy
}

void MainWindow::onFOVChanged(int value)
{
    ui->FOVSizeValuesLabel->setText(QString::number(value));
    // Add functionality to change FOV in Aimmy
}

void MainWindow::onDynamicFOVChanged(int value)
{
    ui->DynamicFOVSizeValuesLabel->setText(QString::number(value));
    // Add functionality to change dynamic FOV in Aimmy
}

void MainWindow::onJitterChanged(int value)
{
    ui->JitterValuesLabel->setText(QString::number(value));
    // Add functionality to change jitter in Aimmy
}

void MainWindow::onYOffsetChanged(int value)
{
    ui->YOffsetValuesLabel->setText(QString::number(value));
    // Add functionality to change Y offset in Aimmy
}

void MainWindow::onXOffsetChanged(int value)
{
    ui->XOffsetValuesLabel->setText(QString::number(value));
    // Add functionality to change X offset in Aimmy
}

void MainWindow::onAiFontSizeChanged(int value)
{
    ui->AIFontSizeValuesLabel->setText(QString::number(value));
    // Add functionality to change AI font size in Aimmy
}

void MainWindow::onBoxWidthChanged(int value)
{
    ui->BoxWidthValuesLabel->setText(QString::number(value));
    // Add functionality to change box width in Aimmy
}

void MainWindow::onOpacityChanged(int value)
{
    ui->OpacityValuesLabel->setText(QString::number(value));
    // Add functionality to change opacity in Aimmy
}

void MainWindow::setupColorButtons()
{
    connect(ui->WindowPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->WindowTextPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->TextPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->ButtonPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->LightPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->MidlightPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->DarkPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->MidPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->BrightTextPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->ButtonTextPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->BasePushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->ShadowPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->HighlightPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->HighlightedTextPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->LinkPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->LinkVisitedPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->AlternateBasePushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->ToolTipBasePushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->ToolTipTextPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
    connect(ui->PlaceholderTextPushButton, &QPushButton::clicked, this, &MainWindow::changeColor);
}

void MainWindow::changeColor()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button)
        return;

    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid())
    {
        button->setStyleSheet(QString("background-color: %1").arg(color.name()));

        QPalette palette = qApp->palette();
        if (button == ui->WindowPushButton)
        {
            palette.setColor(QPalette::Window, color);
        }
        else if (button == ui->WindowTextPushButton)
        {
            palette.setColor(QPalette::WindowText, color);
        }
        else if (button == ui->TextPushButton)
        {
            palette.setColor(QPalette::Text, color);
        }
        else if (button == ui->ButtonPushButton)
        {
            palette.setColor(QPalette::Button, color);
        }
        else if (button == ui->LightPushButton)
        {
            palette.setColor(QPalette::Light, color);
        }
        else if (button == ui->MidlightPushButton)
        {
            palette.setColor(QPalette::Midlight, color);
        }
        else if (button == ui->DarkPushButton)
        {
            palette.setColor(QPalette::Dark, color);
        }
        else if (button == ui->MidPushButton)
        {
            palette.setColor(QPalette::Mid, color);
        }
        else if (button == ui->BrightTextPushButton)
        {
            palette.setColor(QPalette::BrightText, color);
        }
        else if (button == ui->ButtonTextPushButton)
        {
            palette.setColor(QPalette::ButtonText, color);
        }
        else if (button == ui->BasePushButton)
        {
            palette.setColor(QPalette::Base, color);
        }
        else if (button == ui->ShadowPushButton)
        {
            palette.setColor(QPalette::Shadow, color);
        }
        else if (button == ui->HighlightPushButton)
        {
            palette.setColor(QPalette::Highlight, color);
        }
        else if (button == ui->HighlightedTextPushButton)
        {
            palette.setColor(QPalette::HighlightedText, color);
        }
        else if (button == ui->LinkPushButton)
        {
            palette.setColor(QPalette::Link, color);
        }
        else if (button == ui->LinkVisitedPushButton)
        {
            palette.setColor(QPalette::LinkVisited, color);
        }
        else if (button == ui->AlternateBasePushButton)
        {
            palette.setColor(QPalette::AlternateBase, color);
        }
        else if (button == ui->ToolTipBasePushButton)
        {
            palette.setColor(QPalette::ToolTipBase, color);
        }
        else if (button == ui->ToolTipTextPushButton)
        {
            palette.setColor(QPalette::ToolTipText, color);
        }
        else if (button == ui->PlaceholderTextPushButton)
        {
            palette.setColor(QPalette::PlaceholderText, color);
        }

        qApp->setPalette(palette);
    }
}

void MainWindow::loadConfigFiles()
{
    QString configDirectory = "C:/Amm/etc/Aimmy2_CPP/configs";
    loadFilesToList(configDirectory, ui->ConfigList);
}

void MainWindow::loadModelFiles()
{
    QString modelDirectory = "C:/Amm/etc/Aimmy2_CPP/models";
    loadFilesToList(modelDirectory, ui->ModelList);
}

void MainWindow::loadFilesToList(const QString &directoryPath, QListWidget *listWidget)
{
    QDir directory(directoryPath);
    QStringList files = directory.entryList(QStringList() << "*.cfg" << "*.onnx", QDir::Files);
    listWidget->clear();
    foreach (QString filename, files)
    {
        listWidget->addItem(filename);
    }
}

void MainWindow::on_configList_itemClicked(QListWidgetItem *item)
{
    QString filePath = "C:/Amm/etc/Aimmy2_CPP/configs/" + item->text();
    ui->DisplayLoadedConfigLabel->setText(item->text());
    // Load and apply config file logic here
}

void MainWindow::on_modelList_itemClicked(QListWidgetItem *item)
{
    QString filePath = "C:/Amm/etc/Aimmy2_CPP/models/" + item->text();
    ui->DisplayLoadedModelLabel->setText(item->text());
    // Load and apply model file logic here
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (aimAssistActive && event->key() == ui->AimKeybind->text().toInt())
    {
        // Perform aim assist logic
        QPoint enemyPosition; // Placeholder for actual enemy position
        handleAimAssist(enemyPosition);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (aimAssistActive && event->key() == ui->AimKeybind->text().toInt())
    {
        // Stop aim assist logic
    }
}

void MainWindow::handleAimAssist(const QPoint &enemyPosition)
{
    // Placeholder for prediction logic
    QPoint predictedPosition = leadTargetPrediction->predict(enemyPosition, QPoint());
    moveCursorTo(predictedPosition);
}

void MainWindow::moveCursorTo(const QPoint &targetPosition)
{
    // Placeholder for moving cursor logic
}

void MainWindow::onShowFOVToggle(bool checked)
{
    if (checked)
    {
        fovCircle->setRect(0, 0, ui->FOVSlider->value(), ui->FOVSlider->value());
        fovCircle->setPos(QApplication::primaryScreen()->geometry().center() - fovCircle->rect().center());
        fovCircle->setVisible(true);
    }
    else
    {
        fovCircle->setVisible(false);
    }
}

void MainWindow::onUITopmostToggle(bool checked)
{
    if (checked)
    {
        setWindowFlag(Qt::WindowStaysOnTopHint, true);
    }
    else
    {
        setWindowFlag(Qt::WindowStaysOnTopHint, false);
    }
    show(); // Apply the flag change
}

void MainWindow::onAIConfidenceChanged(int value)
{
    ui->AIConfidenceDisplay->display(QString::number(value) + "%");
}
