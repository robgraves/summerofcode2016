#!/usr/bin/python3

# Matthew Page
# 05/22/2016
#
# pygametutorial.py -   working on pygame tutorials
#                       located at
# https://lorenzod8n.wordpress.com/2007/05/25/pygame-tutorial-1-getting-started/

import pygame

#pygame.init()

screen = pygame.display.set_mode((640, 400))

running = 1

while running:
    event = pygame.event.poll()
    if event.type == pygame.QUIT:
        running = 0
    screen.fill((0, 0, 0))
    pygame.draw.line(screen, (0, 0, 255), (0, 0), (639, 479))
    pygame.draw.aaline(screen, (0, 0, 255), (639, 0), (0, 479))
    pygame.display.flip()

