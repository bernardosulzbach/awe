import json

import os
import subprocess


def clean_concatenate(strings):
    for i, string in enumerate(strings):
        strings[i] = string.strip()
    return ' '.join(strings)


if __name__ == '__main__':
    with open('configuration.json') as json_file:
        configuration = json.loads(json_file.read())
    source = configuration['source']
    runs = configuration['runs']
    builds = configuration['builds']
    if not os.path.exists('build'):
        os.mkdir('build')
    os.chdir('build')
    subprocess.run(['cmake', '..'])
    subprocess.run(['cmake', '--build', '.'])
    for build in builds:
        print(build['name'])
        source_path = os.path.join('..', source)
        awe_path = os.path.join('..', 'awe')
        arguments = build['command']
        source_filename = os.path.basename(source_path)
        executable_name = source_filename[:source_filename.rfind('.')]
        arguments.extend(['-o', executable_name])
        arguments.append(source_path)
        arguments.extend(['-I', awe_path, '-L.', '-lawe', '-lm', '-lstdc++', '-Wl,-R.'])
        print(' '.join(arguments))
        subprocess.run(arguments)
        for run in range(runs):
            subprocess.run([os.path.join('.', executable_name)])

    os.chdir('..')
