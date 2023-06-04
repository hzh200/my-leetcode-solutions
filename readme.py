import os
from enum import Enum

Difficulty = Enum('Difficulty', ['Easy', 'Medium', 'Hard'])
Type = Enum('Type', ['Algrithom', 'Function'])
class Language(Enum):
    C = 'C'
    CPP = 'C++'
    Java = 'Java'
    JavaScript = 'JavaScript'
    Go = 'Go'
    Python = 'Python'

language_mapping = {
    'c': Language.C,
    'cpp': Language.CPP,
    'java': Language.Java,
    'js': Language.JavaScript,
    'go': Language.Go,
    'py': Language.Python,
}

class Solution:
    def __init__(self, language, link) -> None:
        self.language = language
        self.link = link

    language: Language
    link: str

class Problem:
    def __init__(self, no, name, link, difficulty, type) -> None:
        self.no = no
        self.name = name
        self.link = link
        self.difficulty = difficulty
        self.type = type

    no: int
    name: str
    link: str
    difficulty: Difficulty
    type: Type
    solutions: list[Solution]

def generate_readme():
    from problems import problems
    problems.sort(key=lambda p: p.no, reverse=True)

    BASE_PATH = '.'
    for p in problems:
        p.solutions = []
        problem_path = os.path.join(BASE_PATH, str(p.type.name).lower() + 's', p.name)
        for solution_path in os.listdir(problem_path):
            suffix = solution_path.split('.')[-1]
            p.solutions.append(Solution(language_mapping[suffix], os.path.join(problem_path, solution_path)))

    readme_head = '''# leetcode-solutions\nMy solutions for leetcode coding problems, maybe using multiple languages.\n'''
    table_head = '''| No | Name | Difficulty | Solutions |\n| -- | -- | -- | -- |\n'''
    
    readme_file = open(os.path.join(BASE_PATH, 'README.md'), 'w') 
    readme_file.write(readme_head)
    readme_file.write('\n')
    readme_file.write(table_head)

    for p in problems:
        solution_items = ['[{0}]({1})'.format(s.language.value, s.link.replace(' ', '%20')) for s in p.solutions]
        table_row = '| {0} | [{1}]({2}) | {3} | {4} |'.format(p.no, p.name, p.link, p.difficulty.name, ', '.join(solution_items))
        readme_file.write(table_row)

    readme_file.close()

if __name__ == "__main__":
    generate_readme()