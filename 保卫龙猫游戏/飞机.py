import pygame
from pygame.locals import *
import random
from sys import exit


class Bullet:  # 雨伞类
    def __init__(self):  # 初始化雨伞的参数
        self.x = 0
        self.y = -1
        self.image = pygame.image.load('um.png').convert_alpha()
        self.active = False

    def move(self):  # 定义雨伞的运行轨迹
        # 激活状态下向上发射
        if self.active:
            self.y -= 3
        # 飞出屏幕就不激活
        if self.y < 0:
            self.active = False

    def restart(self):
        # 重置雨伞位置
        mouse_x, mouse_y = pygame.mouse.get_pos()
        self.x = mouse_x - self.image.get_width() / 2
        self.y = mouse_y - self.image.get_height() / 2
        # 激活雨伞
        self.active = True


# ------------------------------------------------------------

class Enemy:  # 闪电类
    def restart(self):  # 重置闪电的参数
        self.x = random.randint(50, 400)
        self.y = random.randint(-200, -50)
        self.speed = random.random() + 0.05

    def __init__(self):
        self.restart()
        self.image = pygame.image.load('li.png').convert_alpha()

    def move(self):
        if self.y < 800:
            self.y += self.speed
        else:
            self.restart()


# ------------------------------------------------------------

class Plane:
    def restart(self):
        self.x = 440
        self.y = 500

    def __init__(self):
        self.restart()
        self.image = pygame.image.load('cat.png').convert_alpha()

    def move(self):
        x, y = pygame.mouse.get_pos()
        x -= self.image.get_width() / 2
        y -= self.image.get_height() / 2
        self.x = x
        self.y = y


# ------------------------------------------------------------

def checkHit(enemy, bullet):
    if (bullet.x > enemy.x and bullet.x < enemy.x + enemy.image.get_width()) and (
            bullet.y > enemy.y and bullet.y < enemy.y + enemy.image.get_height()):
        enemy.restart()
        bullet.active = False
        return True
    return False


# ------------------------------------------------------------

def checkCrash(enemy, plane):
    if (plane.x + 0.7 * plane.image.get_width() > enemy.x) and (
            plane.x + 0.3 * plane.image.get_width() < enemy.x + enemy.image.get_width()) and (
            plane.y + 0.7 * plane.image.get_height() > enemy.y) and (
            plane.y + 0.3 * plane.image.get_height() < enemy.y + enemy.image.get_height()):
        return True
    return False


pygame.init()

# 隐藏光标
pygame.mouse.set_visible(False)

screen = pygame.display.set_mode((400,500), 0, 32)
pygame.display.set_caption("保卫龙猫")
bg = pygame.image.load('bg.jpg').convert()

plane = Plane()

bullets = []
for i in range(5):
    bullets.append(Bullet())
count_b = len(bullets)
# 激活子弹的序号
index_b = 0
# 发射子弹的间隔
interval_b = 0

enemy = []
for i in range(5):
    enemy.append(Enemy())

# ---------------------游戏主循环-------------------
filename="ending Theme Song.wav"
pygame.mixer.music.load(filename)
pygame.mixer.music.play(loops=0, start=0.0)
gameover = False
score = 0
font = pygame.font.Font(None, 32)
font_over = pygame.font.Font(None, 128)
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
    screen.blit(bg, (0, 0))
    if not gameover:
        # 发射间隔递减
        interval_b -= 1
        # 当间隔小于0，激活一发雨伞
        if interval_b < 0:
            bullets[index_b].restart()
            interval_b = 200
            index_b = (index_b + 1) % count_b
        # 判断每个雨伞的状态
        for b in bullets:
            if b.active:
                b.move()
                screen.blit(b.image, (b.x, b.y))
                for e in enemy:
                    if (checkHit(e, b)):
                        score += 100
        for e in enemy:
            # 如果撞上闪电
            if checkCrash(e, plane):
                gameover = True
            e.move()
            screen.blit(e.image, (e.x, e.y))
        # 检测龙猫的运动
        plane.move()
        screen.blit(plane.image, (plane.x, plane.y))
        text = font.render("Score: %d" % score, 50, (0, 0, 0))
        screen.blit(text, (0, 0))
        font = pygame.font.Font(None, 40)
        survivedtext = font.render(str(int((120000 - pygame.time.get_ticks()) / 60000)) + ":" + str(
            int((120000 - pygame.time.get_ticks()) / 1000 % 60)).zfill(2), True, (0, 0, 0))
        textRect = survivedtext.get_rect()
        textRect.topright = [380, 5]
        screen.blit(survivedtext, textRect)
        if pygame.time.get_ticks() >= 120000:
            youwin = pygame.image.load('youwin.png').convert()
            pygame.display.update()
            screen.blit(youwin, (0, 0))
            text_over = font.render("Game Over", 1, (0, 0, 0))
            screen.blit(text_over, (100,100))
            text = font.render("Score: %d" % score, 1, (0, 0, 0))
            screen.blit(text, (90, 300))
            pygame.quit()

    else:
        text_over = font.render("Game Over", 1, (0, 0, 0))
        screen.blit(text_over, (120, 200))
        text = font.render("Score: %d" % score, 1, (0, 0, 0))
        screen.blit(text, (120, 240))
        if event.type == pygame.MOUSEBUTTONUP:
            # 重置游戏
            plane.restart()
            for e in enemy:
               e.restart()
            for b in bullets:
               b.active = False
               score = 0
               gameover = False

    pygame.display.update()