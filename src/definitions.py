from enum import Enum

class Type(Enum):
    Algrithom = 'Algrithom'
    Data_Structure = 'Data Structure'
    Implementation = 'Implementation'

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
    Bucket = 'bucket'
    SlidingWindow = 'SlidingWindow'

class IndieDomain:
    name: str
    value: str
    def __init__(self, domain: str) -> None:
        domain = ''.join([part.capitalize() for part in domain.split('-')])
        self.name = domain
        self.value = domain

class DataStructuresDomain(Enum):
    Array = 'Array'
    LinkedList = 'Linked List'

class ImplsDomain(Enum):
    Function = 'Function'
    Data_Structure = 'Data Structure'

domain_mapping = {
    'dp': AlgorithmsDomain.DynamicProgramming,
    'dfs': AlgorithmsDomain.DFS,
    'bfs': AlgorithmsDomain.BFS,
    'a-star': AlgorithmsDomain.ASTAR,
    'binary-search': AlgorithmsDomain.BinarySearch,
    'greedy': AlgorithmsDomain.Greedy,
    'backtracking': AlgorithmsDomain.BackTracking,
    'bit': AlgorithmsDomain.Bit,
    'iterate': AlgorithmsDomain.Iterate,
    'two-pointers': AlgorithmsDomain.TwoPointers,
    'hash-table': AlgorithmsDomain.HashTable,
    'heap': AlgorithmsDomain.Heap,
    'math': AlgorithmsDomain.Math,
    'kmp': AlgorithmsDomain.KMP,
    'stack': AlgorithmsDomain.Stack,
    'bucket': AlgorithmsDomain.Bucket,
    'sliding-window': AlgorithmsDomain.SlidingWindow,

    'array': DataStructuresDomain.Array,
    'string': AlgorithmsDomain.String,
    'linked-list': DataStructuresDomain.LinkedList,
}

class Difficulty(Enum):
    Easy = 'Easy'
    Medium = 'Medium'
    Hard = 'Hard'

class Language(Enum):
    C = 'C'
    CPP = 'C++'
    Java = 'Java'
    JavaScript = 'JavaScript'
    Go = 'Go'
    Python = 'Python'
    Typescript = 'TypeScript'

language_mapping = {
    'c': Language.C,
    'cpp': Language.CPP,
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