import pandas as pd

ruta_archivo = '/home/lm/Code/Horus/Pruebas/mpu_silla/mpu copy.csv'

# Lee el archivo CSV
df = pd.read_csv(ruta_archivo)

# print(df['time'])

# Convierte la columna 'time' a enteros eliminando los decimales
df['Aceleracion_X'] = df['Aceleracion_X'] - 1

# Guarda el DataFrame modificado en un nuevo archivo CSV
df.to_csv(ruta_archivo, index=False)