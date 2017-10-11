package com.example.nolanz.sc;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.view.View;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        //need to initialize the first fragment in here
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }

    //This section invokes the options menu in the upper right corner
    //It uses main.xml to create the menu
    /*@Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }*/

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();

        if (id == R.id.nav_charge)
        {
<<<<<<< HEAD
            if(!(currentFragment instanceof ChargeFragment))
            {
                fragmentTransaction.replace(R.id.frag_container, chargeFragment);
<<<<<<< HEAD
                fragmentTransaction.addToBackStack();
                fragmentTransaction.commit();
=======
>>>>>>> parent of 9bba04e... Adding more functionality.
            }
=======
>>>>>>> parent of b1643a9... Adding Fragments
            //Show main page
        }
        else if (id == R.id.nav_instr)
        {
<<<<<<< HEAD
            boolean what = currentFragment instanceof InstructionsFragment;
            if(!(currentFragment instanceof InstructionsFragment))
            {
                fragmentTransaction.replace(R.id.frag_container, instructionsFragment);
                fragmentTransaction.addToBackStack();
                fragmentTransaction.commit();
            }
=======
>>>>>>> parent of 9bba04e... Adding more functionality.
            //Show instructions page
        }
        else if (id == R.id.nav_why)
        {
<<<<<<< HEAD
            boolean what = currentFragment instanceof InstructionsFragment;
            if(!(currentFragment instanceof WhyFragment))
            {
                fragmentTransaction.replace(R.id.frag_container, whyFragment);
                fragmentTransaction.addToBackStack();
                fragmentTransaction.commit();
            }
=======
>>>>>>> parent of 9bba04e... Adding more functionality.
            //Show why it works page
        }
        else if (id == R.id.nav_contact)
        {
<<<<<<< HEAD
            boolean what = currentFragment instanceof InstructionsFragment;
            if(!(currentFragment instanceof ContactFragment))
            {
                fragmentTransaction.replace(R.id.frag_container, contactFragment);
                fragmentTransaction.addToBackStack();
                fragmentTransaction.commit();
            }
=======
>>>>>>> parent of 9bba04e... Adding more functionality.
            //Show contact us page
        }
        /*else if (id == R.id.nav_share)
        {

        }
        else if (id == R.id.nav_send)
        {

        }*/

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }
}
