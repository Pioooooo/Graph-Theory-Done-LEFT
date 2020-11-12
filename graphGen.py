from igraph import *


def saveFig(graph, filename, layout='auto'):
    write(graph, filename + '.svg', 'svg',
          layout=graph.layout(layout))


g = Graph.GRG(3, 1)
g.vs['label'] = ''
saveFig(g, 'graph', 'kk')
g1 = Graph([(0, 1), (1, 2), (2, 0)], directed=True)
g1.vs['label'] = ''
saveFig(g1, 'directed', 'kk')
g1.add_edges([(1, 0)])
saveFig(g1, 'mixed', 'kk')
g2 = Graph([(0, 1), (1, 2), (1, 3)])
g2.vs['label'] = ['s', 'p', 't', 'q']
saveFig(g2, 'diameter_1', 'kk')
g2.add_vertex()
g2.add_edges([(1, 4)])
g2.vs['label'] = ['s', 'm', 'p', 't', 'q']
saveFig(g2, 'diameter_2', 'kk')
g3 = Graph([(0, 1), (1, 2), (1, 3), (3, 4), (3, 5)])
g3.vs['label'] = ['s', 'm', 't', 'n', 'p', 'q']
saveFig(g3, 'diameter_3', 'kk')
