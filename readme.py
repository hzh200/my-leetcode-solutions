import os
import posixpath
from definitions import Type, AlgorithmsDomain, DataStructuresDomain, ImplementationsDomain, IndieDomain, domain_mapping, language_mapping, Solution

WEBSITE_PROBLEMS_URL = 'https://leetcode.cn/problems/'
BASE_PATH = '.'
DOMAINS_PATH = posixpath.join(BASE_PATH, 'domains')
SOLUTIONS_PATH = posixpath.join(BASE_PATH, 'solutions')
DOMAIN_RELATIVE_BASE_PATH = posixpath.join('..', '..')

PROJECT_TITLE = 'my-leetcode-solutions'
PROJECT_DESCRIPTION = 'My solutions for leetcode coding problems, maybe using multiple languages.'

def fetch_problems(sort=True):
    from problems import problems
    if sort:
        problems.sort(key=lambda p: p.no, reverse=True)
    for problem in problems: # Add solutions for problems.
        problem.solutions = []
        solutions_path = posixpath.join(SOLUTIONS_PATH, str(problem.type.value).lower() + 's', problem.name)
        for solution_path in os.listdir(solutions_path):
            type, suffix = solution_path.split('.')
            if problem.type == Type.Implementation:
                problem.solutions.append(Solution(language_mapping[suffix], problem.domain, posixpath.join(solutions_path, solution_path)))
            else:
                problem.solutions.append(Solution(language_mapping[suffix], domain_mapping[type] if type in domain_mapping else IndieDomain(type), posixpath.join(solutions_path, solution_path)))
    return problems

def fetch_domains():
    domains = {}
    domains[Type.Algrithom] = []
    domains[Type.Data_Structure] = []
    domains[Type.Implementation] = []
    for domain in [domain.value for domain in AlgorithmsDomain]:
        domains[Type.Algrithom].append([domain, posixpath.join(DOMAINS_PATH, Type.Algrithom.value + 's', domain + '.md')])
    for domain in [domain.value for domain in DataStructuresDomain]:
        domains[Type.Data_Structure].append([domain, posixpath.join(DOMAINS_PATH, Type.Data_Structure.value + 's', domain + '.md')])
    for domain in [domain.value for domain in ImplementationsDomain]:
        domains[Type.Implementation].append([domain, posixpath.join(DOMAINS_PATH, Type.Implementation.value + 's', domain + '.md')])
    return domains

def get_problem_table_rows():
    table_rows = []
    for problem in fetch_problems():
        if problem.type.value == Type.Algrithom.value:
            solution_items = ['[{0}-{1}]({2})'.format(s.domain.value, s.language.value, s.link.replace(' ', '%20')) for s in problem.solutions]
        else:
            solution_items = ['[{0}]({1})'.format(s.language.value, s.link.replace(' ', '%20')) for s in problem.solutions]
        table_rows.append([problem.no, problem.name, WEBSITE_PROBLEMS_URL + problem.name.replace(' ', '-'), problem.difficulty.value, ', '.join(solution_items)])
    return table_rows

def get_domain_table_rows(domain_title):
    table_rows = []
    for problem in fetch_problems():
        solutions = ['[{0}]({1})'.format(solution.language.value, posixpath.join(DOMAIN_RELATIVE_BASE_PATH, solution.link.replace(' ', '%20'))) 
                        for solution in filter(lambda solution: solution.domain.value == domain_title, problem.solutions)]
        if len(solutions) == 0:
            continue
        table_rows.append([problem.no, problem.name, WEBSITE_PROBLEMS_URL + problem.name.replace(' ', '-'), ', '.join(solutions)])
    return table_rows

def get_domain_index_sections(domains):
    return [[type.value + 's', ' | '.join(['[{0}]({1})'.format(domain[0], domain[1].replace(' ', '%20')) for domain in type_domains])] for type, type_domains in domains.items()]

def generate_domain_file(domain):
    domain_title, domain_path = domain

    table_head = '| No | Name | Solution |'
    table_spliter = '| -- | -- | -- |'
    table_body = '\n'.join(['{0} | [{1}]({2}) | {3}'.format(row[0], row[1], row[2], row[3]) for row in get_domain_table_rows(domain_title)])

    os.makedirs(os.path.dirname(domain_path), exist_ok=True)
    domain_file = open(domain_path, 'w')
    domain_file.write('#' + ' ' + domain_title + '\n')
    domain_file.write(table_head + '\n')
    domain_file.write(table_spliter + '\n')
    domain_file.write(table_body + '\n')
    domain_file.write('\n')
    domain_file.close()

def generate_readme_file(): # Generate readme file.
    domains = fetch_domains()
    for _, type_domains in domains.items():
        for domain in type_domains:
            generate_domain_file(domain)

    domain_title = 'domains'
    problems_title = 'problems'
    domain_index = '\n'.join(['#### {0}\n{1}'.format(title, content) for title, content in get_domain_index_sections(domains)])

    table_head = '| No | Name | Difficulty | Solutions |'
    table_spliter = '| -- | -- | -- | -- |'
    table_body = '\n'.join(['| {0} | [{1}]({2}) | {3} | {4} |'.format(row[0], row[1], row[2], row[3], row[4]) for row in get_problem_table_rows()])

    readme_file = open(posixpath.join(BASE_PATH, 'README.md'), 'w')
    readme_file.write('#' + ' ' + PROJECT_TITLE + '\n')
    readme_file.write(PROJECT_DESCRIPTION + '\n')
    readme_file.write('\n')
    readme_file.write('## {0}\n'.format(domain_title))
    readme_file.write(domain_index + '\n')
    readme_file.write('\n')
    readme_file.write('## {0}\n'.format(problems_title))
    readme_file.write(table_head + '\n')
    readme_file.write(table_spliter + '\n')
    readme_file.write(table_body + '\n')
    readme_file.write('\n')
    readme_file.close()

def main(): # Generate README.md and corresponding domain markdown files automatically.
    generate_readme_file()

if __name__ == "__main__":
    main()
