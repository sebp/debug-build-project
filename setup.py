from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            "mwe._ext",
            sources=["src/mwe/_ext.c"],
        ),
    ],
)
