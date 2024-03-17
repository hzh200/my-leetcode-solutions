from enum import Enum

class Type(Enum):
    Algrithom = 'Algrithom'
    Data_Structure = 'Data Structure'
    Implementation = 'Implementation'

class AlgorithmsDomain(Enum):
    String = 'String'
    DynamicProgramming = 'DP'
    Search = 'Search'
    Greedy = 'Greedy'
    BackTracking = 'BackTracking'

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

class ImplementationsDomain(Enum):
    Function = 'Function'
    Data_Structure = 'Data Structure'

domain_mapping = {
    'string': AlgorithmsDomain.String,
    'dp': AlgorithmsDomain.DynamicProgramming,
    'search': AlgorithmsDomain.Search,
    'greedy': AlgorithmsDomain.Greedy,
    'backtracking': AlgorithmsDomain.BackTracking,

    'array': DataStructuresDomain.Array,
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
    domain: AlgorithmsDomain | DataStructuresDomain | ImplementationsDomain | IndieDomain
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
    domain: ImplementationsDomain # for Implementation type only.
    solutions: list[Solution]