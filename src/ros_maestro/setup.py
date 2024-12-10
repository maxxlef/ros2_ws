from setuptools import setup

package_name = 'maestro'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    install_requires=['setuptools'],
    zip_safe=True,
    package_data={
        # Inclure les fichiers non Python, si nécessaire
        # 'maestro': ['config/*.yaml'],  # Exemple d'inclusion de fichiers de configuration
    },
)
