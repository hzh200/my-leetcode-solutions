from enum import Enum

class Type(Enum):
    Algrithom = 'Algrithom'
    Function = 'Function'
    Data_Structure = 'Data Structure'

class AlgorithmsDomain(Enum):
    String = 'String'
    DynamicProgramming = 'DP'
    Search = 'Search'
    Greedy = 'Greedy'

class DataStructuresDomain(Enum):
    Array = 'Array'
    LinkedList = 'Linked List'
    Cache = 'Cache'
    Advanced = 'Advanced'

class FunctionsDomain(Enum):
    Function = 'Function'
    Data_Structure = 'Data Structure'

domain_mapping = {
    'string': AlgorithmsDomain.String,
    'dp': AlgorithmsDomain.DynamicProgramming,
    'search': AlgorithmsDomain.Search,
    'greedy': AlgorithmsDomain.Greedy,

    'array': DataStructuresDomain.Array,
    'list': DataStructuresDomain.LinkedList,
    'advanced': DataStructuresDomain.Advanced,

    'func': FunctionsDomain.Function
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

language_mapping = {
    'c': Language.C,
    'cpp': Language.CPP,
    'java': Language.Java,
    'js': Language.JavaScript,
    'go': Language.Go,
    'py': Language.Python,
}

class Solution:
    def __init__(self, language, domain, link) -> None:
        self.language = language
        self.domain = domain
        self.link = link

    language: Language
    domain: AlgorithmsDomain | DataStructuresDomain | FunctionsDomain
    link: str

class Problem:
    def __init__(self, no, name, difficulty, type) -> None:
        self.no = no
        self.name = name
        self.difficulty = difficulty
        self.type = type

    no: int
    name: str
    difficulty: Difficulty
    type: Type
    solutions: list[Solution]