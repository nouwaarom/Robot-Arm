project('RobotArm', 'cpp')

gl_dep = dependency('gl')
glu_dep = dependency('glu')
threads_dep = dependency('threads')

controller_sources = [
    'src/main.cpp',
    'src/ControllerInterface.cpp',
    'src/denavit.cpp',
    'src/RLink.cpp',
    'src/Robot.cpp',
    'src/BMPImage.cpp'
]

executable('armcontrol',
           controller_sources,
           dependencies: [gl_dep, glu_dep, threads_dep],
           link_args: ['-lglut', '-ldl', '-fPIC', '-static-libgcc', '-Wl,--start-group'],
           objects: 'libs/libsimple_arm_controller.a'
          )
