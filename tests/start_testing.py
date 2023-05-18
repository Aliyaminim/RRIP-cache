import os

os.system('echo Testing has started!')
os.system('echo ')
os.system('echo "Recency friendly access pattern tests:"')
os.system('for i in recency_friendly_access_pattern/*.in; do echo $i; done')
os.system('echo ')
os.system('echo "Thrashing access pattern tests:"')
os.system('for i in thrashing_access_pattern/*.in; do echo $i; done')
os.system('echo ')
os.system('echo "Mixed access pattern(1) tests:"')
os.system('for i in mixed_access1_pattern/*.in; do echo $i; done')
os.system('echo ')
os.system('echo "Mixed access pattern(2) tests:"')
os.system('for i in mixed_access2_pattern/*.in; do echo $i; done')


