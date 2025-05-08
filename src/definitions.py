from enum import Enum

class Type(Enum):
    Algrithom = 'Algrithom'
    Data_Structure = 'Data Structure'
    Implementation = 'Implementation'

class ImplsDomain(Enum):
    Function = 'Function'
    Data_Structure = 'Data Structure'

class AlgorithmsDomain(Enum):
    String = 'String'
    DynamicProgramming = 'DP'
    DFS = 'DFS'
    BFS = 'BFS'
    ASTAR = 'AStar'
    BinarySearch = 'BinarySearch'
    Greedy = 'Greedy'
    BackTracking = 'BackTracking'
    Bit = 'Bit'
    Iterate = 'Iterate'
    TwoPointers = 'TwoPointers'
    HashTable = 'HashTable'
    Heap = 'Heap'
    Math = 'Math'
    KMP = 'KMP'
    Stack = 'Stack'
    Bucket = 'Bucket'
    SlidingWindow = 'SlidingWindow'
    Simulating = 'Simulate'
    SortedSet = 'SortedSet'
    Set = 'Set'

class DataStructuresDomain(Enum):
    Array = 'Array'
    LinkedList = 'Linked List'
    Tree = 'Tree'

class IndieDomain:
    name: str
    value: str
    def __init__(self, domain: str) -> None:
        domain = ''.join([part.capitalize() for part in domain.split('-')])
        self.name = domain
        self.value = domain

domain_mapping = {}

for item in AlgorithmsDomain.__members__.items():
    domain_name = ""
    for c in list(item[1].value):
        if c >= 'A' and c <= 'Z':
            if len(domain_name) != 0:
                domain_name += '_'
            domain_name += c.upper()
        else:
            domain_name += c
    domain_mapping[domain_name] = item[1]

for item in DataStructuresDomain.__members__.items():
    domain_name = ""
    for c in list(item[1].value):
        if c >= 'A' and c <= 'Z':
            if len(domain_name) != 0:
                domain_name += '_'
            domain_name += c.upper()
        else:
            domain_name += c
    domain_mapping[domain_name] = item[1]

class Difficulty(Enum):
    Easy = 'Easy'
    Medium = 'Medium'
    Hard = 'Hard'

class Language(Enum):
    C = 'C'
    CC = 'C++'
    Java = 'Java'
    JavaScript = 'JavaScript'
    Go = 'Go'
    Python = 'Python'
    Typescript = 'TypeScript'

language_mapping = {
    'c': Language.C,
    'cc': Language.CC,
    'java': Language.Java,
    'js': Language.JavaScript,
    'ts': Language.Typescript,
    'go': Language.Go,
    'py': Language.Python,
}

class Solution:
    def __init__(self, language, domain, link) -> None:
        self.language = language
        self.domain = domain
        self.link = link

    language: Language
    domain: AlgorithmsDomain | DataStructuresDomain | ImplsDomain | IndieDomain
    link: str

class Problem:
    def __init__(self, no, name, difficulty, type, domain=None) -> None:
        self.no = no
        self.name = name
        self.difficulty = difficulty
        self.type = type
        self.domain = domain

    no: int
    name: str
    difficulty: Difficulty
    type: Type
    domain: ImplsDomain # for Implementation type only.
    solutions: list[Solution]