from typing import List

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        x = 0
        y = 0
        direction = 0
        obstacle_set = set(map(tuple, obstacles))  
        

        for command in commands:
            if command == -2:
                direction = (direction - 1) % 4
            elif command == -1:
                direction = (direction + 1) % 4
            else:
                for _ in range(command):
                    if direction == 0:
                        if (x, y + 1) in obstacle_set:
                            break
                        y += 1
                    elif direction == 1:
                        if (x + 1, y) in obstacle_set:
                            break
                        x += 1
                    elif direction == 2:
                        if (x, y - 1) in obstacle_set:
                            break
                        y -= 1
                    elif direction == 3:
                        if (x - 1, y) in obstacle_set:
                            break
                        x -= 1

        return x ** 2 + y ** 2

if __name__ == '__main__':
    s = Solution()
    commands = [4, -1, 3]
    obstacles = []
    print(s.robotSim(commands, obstacles))