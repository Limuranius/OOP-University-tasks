"use strict";
// _______________________________________________________Продукты_____________________________________________________
// Рука робота
class Arm {
    constructor(info = "None") {
        this.info = info;
    }
}
// Нога робота
class Leg {
    constructor(info = "None") {
        this.info = info;
    }
}
// Робот
class Robot {
    constructor() {
        this.leftArm = new Arm();
        this.rightArm = new Arm();
        this.leftLeg = new Leg();
        this.rightLeg = new Leg();
        this.hasNightVision = false;
    }
    setLeftArm(arm) {
        this.leftArm = arm;
    }
    setRightArm(arm) {
        this.rightArm = arm;
    }
    setLeftLeg(leg) {
        this.leftLeg = leg;
    }
    setRightLeg(leg) {
        this.rightLeg = leg;
    }
    setNightVision(value) {
        this.hasNightVision = value;
    }
}
// Информация о роботе
class RobotInfo {
    constructor() {
        this.leftArmInfo = "None";
        this.rightArmInfo = "None";
        this.leftLegInfo = "None";
        this.rightLegInfo = "None";
        this.hasNightVisionInfo = false;
    }
    setLeftArmInfo(arm) {
        this.leftArmInfo = arm;
    }
    setRightArmInfo(arm) {
        this.rightArmInfo = arm;
    }
    setLeftLegInfo(leg) {
        this.leftLegInfo = leg;
    }
    setRightLegInfo(leg) {
        this.rightLegInfo = leg;
    }
    setNightVisionInfo(value) {
        this.hasNightVisionInfo = value;
    }
    printInfo() {
        console.log(`Left arm: ${this.leftArmInfo}
Right arm: ${this.rightArmInfo}
Left leg: ${this.leftLegInfo}
Right leg: ${this.rightLegInfo}
Night vision: ${this.hasNightVisionInfo}`);
    }
}
// Строитель робота
class RobotBuilder {
    constructor() {
        this.result = new Robot();
    }
    reset() {
        this.result = new Robot();
    }
    setLeftArm(arm) {
        this.result.setLeftArm(arm);
    }
    setRightArm(arm) {
        this.result.setRightArm(arm);
    }
    setLeftLeg(leg) {
        this.result.setLeftLeg(leg);
    }
    setRightLeg(leg) {
        this.result.setRightLeg(leg);
    }
    setNightVision(value) {
        this.result.setNightVision(value);
    }
    getResult() {
        return this.result;
    }
}
// Строитель информации о роботе
class RobotInfoBuilder {
    constructor() {
        this.result = new RobotInfo();
    }
    reset() {
        this.result = new RobotInfo();
    }
    setLeftArm(arm) {
        this.result.setLeftArmInfo(arm.info);
    }
    setRightArm(arm) {
        this.result.setRightArmInfo(arm.info);
    }
    setLeftLeg(leg) {
        this.result.setLeftLegInfo(leg.info);
    }
    setRightLeg(leg) {
        this.result.setRightLegInfo(leg.info);
    }
    setNightVision(value) {
        this.result.setNightVisionInfo(value);
    }
    getResult() {
        return this.result;
    }
}
// _______________________________________________________Директор_____________________________________________________
class RobotDirector {
    buildBasicRobot(builder) {
        builder.reset();
        builder.setLeftArm(new Arm("Левая рука. Версия 1.6. Умеет чесать спину"));
        builder.setRightArm(new Arm("Правая рука. Версия 2.0 Способна удлиняться"));
        builder.setLeftLeg(new Leg("Левая нога. Версия 1.2. Осторожно, возможно самовоспламенение"));
        builder.setRightLeg(new Leg("Правая нога. Версия 1.3. Позолоченная"));
        builder.setNightVision(false);
        return builder;
    }
    buildKillerMachine(builder) {
        builder.reset();
        builder.setLeftArm(new Arm("Левая рука. Версия 5.0. Оснащена ракетницей и лазерным мечом"));
        builder.setRightArm(new Arm("Правая рука. Версия 5.0. Встроенная бензопила"));
        builder.setLeftLeg(new Leg("Левая нога. Версия 5.0. Оснащена ракетными ускорителями"));
        builder.setRightLeg(new Leg("Правая нога. Версия 5.0. Оснащена ракетными ускорителями"));
        builder.setNightVision(true);
        return builder;
    }
}
function main() {
    let director = new RobotDirector();
    let builderR = new RobotBuilder();
    let builderI = new RobotInfoBuilder();
    director.buildBasicRobot(builderR);
    director.buildBasicRobot(builderI);
    let bot1 = builderR.getResult();
    let bot1Info = builderI.getResult();
    director.buildKillerMachine(builderR);
    director.buildKillerMachine(builderI);
    let bot2 = builderR.getResult();
    let bot2Info = builderI.getResult();
    console.log("Bot 1:");
    bot1Info.printInfo();
    console.log("Bot 2:");
    bot2Info.printInfo();
}
main();
