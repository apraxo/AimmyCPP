#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QColorDialog>
#include <QDir>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "KeybindEventFilter.h"
#include "LeadTargetPrediction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    KeybindEventFilter *dynamicFOVKeybindFilter;
    KeybindEventFilter *outputBotActionKeybindFilter;
    KeybindEventFilter *botKeybindFilter;
    KeybindEventFilter *aimKeybindFilter;
    KeybindEventFilter *stopKeybindFilter;

    QColor currentColor;
    bool aimAssistActive;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *fovCircle;
    LeadTargetPrediction *leadTargetPrediction;

private slots:
    void onSensitivityChanged(int value);
    void onEMASmoothingChanged(int value);
    void onPredictionMethodChanged(const QString &method);
    void onAimAssistToggle(bool checked);
    void onPredictionsToggle(bool checked);
    void onEMASmoothingToggle(bool checked);
    void onDynamicFOVKeybindChanged(const QString &keySequence);
    void onOutputBotActionKeybindChanged(const QString &keySequence);
    void onBotKeybindChanged(const QString &keySequence);
    void onAimKeybindChanged(const QString &keySequence);
    void onStopKeybindChanged(const QString &keySequence);
    void onFOVChanged(int value);
    void onDynamicFOVChanged(int value);
    void onJitterChanged(int value);
    void onYOffsetChanged(int value);
    void onXOffsetChanged(int value);
    void onAiFontSizeChanged(int value);
    void onBoxWidthChanged(int value);
    void onOpacityChanged(int value);
    void onShowFOVToggle(bool checked);
    void onUITopmostToggle(bool checked);
    void onAIConfidenceChanged(int value);
    void setupColorButtons();
    void changeColor();
    void loadConfigFiles();
    void loadModelFiles();
    void loadFilesToList(const QString &directoryPath, QListWidget *listWidget);
    void on_configList_itemClicked(QListWidgetItem *item);
    void on_modelList_itemClicked(QListWidgetItem *item);

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void handleAimAssist(const QPoint &enemyPosition);
    void moveCursorTo(const QPoint &targetPosition);
};

#endif // MAINWINDOW_H
