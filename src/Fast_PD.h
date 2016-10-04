//#############################################################################
//#
//# Fast_PD.h:
//#  Header file containing "CV_Fast_PD" class interface
//#
//#############################################################################

#ifndef __FAST_PD_H__
#define __FAST_PD_H__

#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include "graph.h"
#include "common.h"

#define DIST(l0,l1)   (_dist[l1*_numlabels+l0])
#define UPDATE_BALANCE_VAR0(y,d,h0,h1) { (y)+=(d); (h0)+=(d); (h1)-=d; }
#define NEW_LABEL(n) ((n)->parent && !((n)->is_sink))
#define REV(a) ((a)+1)

//#############################################################################
//#
//# Classes & types
//#
//#############################################################################

//=============================================================================
// @class   CV_Fast_PD
// @author  Nikos Komodakis
//=============================================================================
//


class CV_Fast_PD
{
public:
    
    typedef Graph::Real Real;
    
    //
    // NOTE: "lcosts" is modified by member functions of this class
    //
    CV_Fast_PD( int numpoints, int numlabels, Real *lcosts,
               int numpairs , int *pairs   ,
               Real *dist   , int max_iters,
               Real *wcosts  );
    
    
    ~CV_Fast_PD( void );
    
    void init_duals_primals( void );
    
    void inner_iteration( Graph::Label label );
    
    void inner_iteration_adapted( Graph::Label label );
    
    void track_source_linked_nodes( Graph::Label label );
    
    void run( void );
    
    void fillGraph( Graph *_graph );
    
    void createNeighbors( void );
    
    double MAX( double a, double b );
    double MIN( double a, double b );
    
    static void err_fun(char * msg)
    {
        printf("%s",msg);
    }
    
    // custom helper functions
    Graph::Label getLabel( int position );
    
    struct Node_info
    {
        Graph::Label label; // current label
        Real height; // active height of node
        TIME time; // timestamp of change
        int next;    
        int prev;
        int *pairs; // neighboring edges
        int num_pairs;
    };
    
    int           _numpoints;
    int           _numpairs;
    int           _numlabels;
    int           _max_iters;
    Real         *_h; // height variables
    Real         *_y; // balance variables
    Real         *_dist; // distance function for pairwise potential
    int          *_pairs;
    Graph::node  *_all_nodes; // Nodes and edges 
    Graph::arc   *_all_arcs;  // of max-flow graphs
    Graph       **_all_graphs;
    int          *_source_nodes_tmp1; // Auxiliary lists for keeping
    int          *_source_nodes_tmp2; // track of source-linked nodes
    Real         *_wcosts; // Weights of MRF pairwise potentials
    int           _iter;
    Node_info    *_pinfo; // info per MRF node
    
private:
    
    // auxiliary data structures and variables
    //
    struct Pair_info
    {
        int i0, i1;
        TIME time;
    };
    
    struct Arc_info
    {
        int head, tail;
        Real balance;
    };
    
    Arc_info     *_einfo;
    double        _APF; // MRF energy
    int           _time;
    Pair_info    *_pair_info;
    int           _active_list;
    int           _APF_change_time;
    Graph::node **_children;
    int          *_pairs_arr;
    
    // Assignment or copying are not allowed
    //
    CV_Fast_PD( const CV_Fast_PD &other );
    CV_Fast_PD operator=( const CV_Fast_PD &other );
};

#endif /* __FAST_PD_H__ */

//#############################################################################
//#
//# EOF
//#
//#############################################################################

